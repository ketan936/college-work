active proctype switch()   /* outgoing calls only */
{
Idle:
	if
	:: tpc?offhook ->
		printf("dialtone\n"); goto Dial
	fi;
Dial:
	if
	:: tpc?digits ->
		printf("notone\n"); goto Wait
	:: tpc?onhook ->
		printf("notone\n"); goto Idle
	fi;
Wait:
	if
	:: printf("ringtone\n") -> goto Connect;
	:: printf("busytone\n") -> goto Busy
	fi;
Connect:
	if
	:: printf("busytone\n") -> goto Busy
	:: printf("notone\n")   -> goto Busy
	fi;
Busy:
	if
	:: tpc?onhook ->
		printf("notone\n"); goto Idle
	fi
}
