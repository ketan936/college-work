proctype remote(chan inp; chan out)
{
Idle:
	if
	:: inp?iam -> goto Dialing
	fi;
Dialing:
	if
	:: out!acm -> goto Ringing
	:: out!rel -> goto Busy
	:: inp?rel -> goto Hangup
	fi;
Ringing:
	if
	:: out!anm -> goto Talking
	:: out!rel -> goto Busy
	:: inp?rel -> goto Hangup
	fi;
Talking:
	if
	:: out!rel -> goto Busy
	:: inp?rel -> goto Hangup
	fi;
Hangup:
	out!rlc -> goto Idle;
Busy:
	if
	:: inp?rlc -> goto Idle
	:: inp?rel -> goto Race
	fi;

Race:	if
	:: out!rlc -> goto Busy
	:: inp?rlc ->	/* added */
		out!rlc; goto Idle
	fi
}
