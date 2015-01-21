mtype = { iam, acm, anm, rel, rlc }; /* ss7 messages */

chan rms = [1] of { mtype }; /* channel to remote switch */

active proctype switch_ss7()
{
Idle:
    if
    :: tpc?offhook -> printf("dialtone\n"); goto Dial
    fi;
Dial:
    if
    :: tpc?digits -> printf("notone\n"); rms!iam;
                     goto Wait
    :: tpc?onhook -> printf("notone\n"); goto Idle
    fi;
Wait:
    if
    :: tpc?acm -> printf("ringtone\n"); goto Wait
    :: tpc?anm -> printf("notone\n"); goto Connect
    :: tpc?rel -> rms!rlc; printf("busytone\n");
                  goto Busy
    :: tpc?onhook -> rms!rel; goto Zombie1
    fi;
Connect:
    if
    :: tpc?rel -> rms!rlc; printf("busytone\n");
                  goto Busy
    :: tpc?onhook -> rms!rel; goto Zombie1
    fi;
Busy:		/* offhook, waiting for onhook */
    if
    :: tpc?onhook -> printf("notone\n"); goto Idle
    fi;

Zombie1:	/* onhook, waiting for rlc */
    if
    :: tpc?rel -> rms!rlc; goto Zombie1
    :: tpc?rlc -> goto Idle
    :: tpc?offhook -> goto Zombie2
    fi;
Zombie2:	/* offhook, waiting for rlc */
    if
    :: tpc?rel -> rms!rlc; goto Zombie2
    :: tpc?rlc -> goto Busy
    :: tpc?onhook -> goto Zombie1
    fi
}
