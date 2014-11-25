#ifdef GLOBAL
byte c;
#endif

active proctype merino()
{
#ifndef GLOBAL
	byte c;
#endif
	if
	:: c = 0
	:: c = 1
	:: c = 2
	fi;
	do
	:: c < 2 -> c++
	:: c > 0 -> c--
	od
}
