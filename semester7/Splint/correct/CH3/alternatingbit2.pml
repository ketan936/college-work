mtype = { msg, ack };

chan	to_sndr = [2] of { mtype, bit };
chan	to_rcvr = [2] of { mtype, bit };

active proctype Sender()
{	bool seq_out, seq_in;

	/* obtain first message */
	do
	:: to_rcvr!msg(seq_out) ->
		to_sndr?ack(seq_in);
		if
		:: seq_in == seq_out ->
			/* obtain new message */
			seq_out = 1 - seq_out;
		:: else
		fi
	od
}

active proctype Receiver()
{	bool seq_in;

	do
	:: to_rcvr?msg(seq_in) ->
		to_sndr!ack(seq_in)
	:: timeout ->	/* recover from msg loss */
		to_sndr!ack(seq_in)
	od
}
