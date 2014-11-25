mtype = { offhook, digits, onhook };

chan tpc = [0] of { mtype };

active proctype subscriber()
{
Idle:	tpc!offhook;

Busy:	if
	:: tpc!digits -> goto Busy
	:: tpc!onhook -> goto Idle
	fi
}
