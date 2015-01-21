proctype session_ss7(chan inp; chan out)
{
Idle:
    if
    :: inp?offhook -> printf("dialtone\n"); goto Dial
    fi;
Dial:
    if
    :: inp?digits -> printf("notone\n");
                     out!iam; goto Wait
    :: inp?onhook -> printf("notone\n"); goto Idle
    fi;
Wait:
    if
    :: inp?acm -> printf("ringtone\n"); goto Wait
    :: inp?anm -> printf("notone\n"); goto Connect
    :: inp?rel -> out!rlc; printf("busytone\n"); goto Busy
    :: inp?onhook -> out!rel; goto Zombie1
    :: inp?digits -> goto Wait /* added */
    fi;
Connect:
    if
    :: inp?rel -> out!rlc; printf("busytone\n"); goto Busy
    :: inp?onhook -> out!rel; goto Zombie1
    :: inp?digits -> goto Connect /* added */
    fi;
Busy:		/* offhook, waiting for onhook */
    if
    :: inp?onhook -> printf("notone\n"); goto Idle
    :: inp?digits -> goto Busy /* added */	
    fi;
Zombie1:	/* onhook, waiting for rlc */
    if
    :: inp?rel -> out!rlc; goto Zombie1
    :: inp?rlc -> goto Idle
    :: inp?offhook -> goto Zombie2
    :: inp?acm -> goto Zombie1 /* added */
    :: inp?anm -> goto Zombie1 /* added */
    fi;
Zombie2:	/* offhook, waiting for rlc */
    if
    :: inp?rel -> out!rlc; goto Zombie2
    :: inp?rlc -> goto Busy
    :: inp?onhook -> goto Zombie1
    :: inp?digits -> goto Zombie2 /* added */
    fi
}
