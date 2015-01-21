active proctype switch()
{	mtype x;

	atomic
	{	run session_ss7(sess[0], rms[0]);
		run session_ss7(sess[1], rms[1]);
		run remote(rms[0], sess[0]);
		run remote(rms[1], sess[1])
	};
end:	do
	:: tpc?x ->
		if
		:: x == offhook ->
			assert(s_state == idle);
			s_state = busy;
			sess[0]!x
		:: x == onhook ->
			assert(s_state != idle);
			if
			:: s_state == busy ->
				sess[0]!x
			:: else ->
				sess[0]!x; sess[1]!x
			fi;
			s_state = idle
		:: x == flash ->
			assert(s_state != idle);
			if
			:: s_state == busy ->
				sess[1]!offhook;
				s_state = setup
			:: s_state == setup ->
				s_state = threeway
			:: s_state == threeway ->
				sess[1]!onhook;
				s_state = busy
			fi
		:: else ->
			if
			:: s_state == idle
				/* ignored */
			:: s_state == busy ->
				sess[0]!x
			:: else ->
				sess[1]!x
			fi
		fi
	od
}
