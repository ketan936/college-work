chan sess = [0] of { mtype };

mtype = { idle, busy };	/* call states */
mtype s_state = idle;

active proctype switch()
{	mtype x;

	atomic
	{	run session_ss7(sess, rms);
		run remote_ss7(rms, sess)
	};
end:	do
	:: tpc?x ->
		if
		:: x == offhook ->
			assert(s_state == idle);
			s_state = busy
		:: x == onhook ->
			assert(s_state == busy);
			s_state = idle
		:: else
		fi;
		sess!x	/* forward message */
	od
}
