mtype = { a, b };

chan ch = [1] of { mtype };

active proctype A() { ch?a }

active proctype B() { ch?b }

active proctype C()
{	if
	:: ch!a
	:: ch!b
	fi
}
