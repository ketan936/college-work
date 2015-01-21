mtype = { msg, ack, nak };

chan q = [2] of { mtype, byte };
chan r = [2] of { mtype };

active proctype S()
{	byte s = 1;
#if 0
	xs q;	/* assert that only S sends to chan q */
	xr r;	/* and only S retrieves from chan r */
#endif
	do
	:: q!msg(s);
		if
		:: r?ack; s++
		:: r?nak
		fi
	od
}
active proctype R()
{	byte ns, s;
#if 0
	xs r;	/* only R sends messages to chan r */
	xr q;	/* only R retrieves messages from chan q */
#endif
	do
	:: q?msg(ns);
		if
		:: (ns == s+1) -> s = ns; r!ack
		:: else -> r!nak
		fi
	od

}
