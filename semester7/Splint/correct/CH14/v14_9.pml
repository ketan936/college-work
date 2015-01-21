active proctype remote_ss7()
{
Idle:
	if
	:: rms?iam -> goto Dialing
	fi;
Dialing:
	if
	:: tpc!acm -> goto Ringing
	:: tpc!rel -> goto Hangup
	:: rms?rel -> goto Busy
	fi;
Ringing:
	if
	:: tpc!anm -> goto Talking
	:: tpc!rel -> goto Hangup
	:: rms?rel -> goto Busy
	fi;
Talking:
	if
	:: tpc!rel -> goto Hangup
	:: rms?rel -> goto Busy
	fi;
Hangup:
	if
	:: rms?rlc -> goto Idle
	:: rms?rel -> goto Race
	fi;
Busy:
	if
	:: rms?rlc -> goto Idle
	fi;

Race:	if
	:: tpc!rlc -> goto Busy
	fi
}
