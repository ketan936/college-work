init {	/* Figure 8.3 */

	byte x;
S0:	if
	:: x = 1; goto S1
	:: x = 2; goto S2
	fi;
S1:	x++;
S2:	x++;
E:	assert(false)
}
