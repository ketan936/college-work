mtype last_sent;

active proctype subscriber()
{
Idle:	tpc!offhook;
	last_sent = offhook;

Busy:	if
	:: atomic { tpc!digits ->
		last_sent = digits;
		goto Busy
	   }
	:: atomic { tpc!flash ->
		last_sent = flash;
		goto Busy
	   }
	:: atomic { tpc!onhook ->
		last_sent = onhook;
		goto Idle
	   }
	fi
}
