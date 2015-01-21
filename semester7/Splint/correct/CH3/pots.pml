mtype = { offhook, dialtone, number, ringing,
	busy, connected, hangup, hungup };

chan line = [0] of { mtype, chan };

active proctype pots()
{	chan who;
idle:	line?offhook,who;
	{ 	who!dialtone;
		who?number;
		if
		:: who!busy; goto zombie
		:: who!ringing ->
			who!connected;
			if
			:: who!hungup; goto zombie
			:: skip
			fi
		fi
	} unless
	{	if
		:: who?hangup -> goto idle
		:: timeout -> goto zombie
		fi
	}
zombie:	who?hangup; goto idle
}

active proctype subscriber()
{	chan me = [0] of { mtype };
idle:	line!offhook,me;
	me?dialtone;
	me!number;
	if
	:: me?busy
	:: me?ringing ->
		if
		:: me?connected;
			if
			:: me?hungup
			:: timeout
			fi
		:: skip
		fi
	fi;
	me!hangup; goto idle
}
