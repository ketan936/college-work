mtype = { msg0, msg1, ack0, ack1 };

chan	to_sndr = [2] of { mtype };
chan	to_rcvr = [2] of { mtype };

active proctype Sender()
{
again:	to_rcvr!msg1;
	to_sndr?ack1;
	to_rcvr!msg0;
	to_sndr?ack0;
	goto again
}

active proctype Receiver()
{
again:	to_rcvr?msg1;
	to_sndr!ack1;
	to_rcvr?msg0;
	to_sndr!ack0;
	goto again
}
