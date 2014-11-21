#define rand	pan_rand
#if defined(HAS_CODE) && defined(VERBOSE)
	printf("Pr: %d Tr: %d\n", II, t->forw);
#endif
	switch (t->forw) {
	default: Uerror("bad forward move");
	case 0:	/* if without executable clauses */
		continue;
	case 1: /* generic 'goto' or 'skip' */
		IfNotBlocked
		_m = 3; goto P999;
	case 2: /* generic 'else' */
		IfNotBlocked
		if (trpt->o_pm&1) continue;
		_m = 3; goto P999;

		 /* PROC :init: */
	case 3: /* STATE 1 - line 14 "pan_in" - [(run hello())] (0:0:0 - 1) */
		IfNotBlocked
		reached[2][1] = 1;
		if (!(addproc(0)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 4: /* STATE 2 - line 15 "pan_in" - [(run world())] (0:0:0 - 1) */
		IfNotBlocked
		reached[2][2] = 1;
		if (!(addproc(1)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 5: /* STATE 3 - line 17 "pan_in" - [-end-] (0:0:0 - 1) */
		IfNotBlocked
		reached[2][3] = 1;
		if (!delproc(1, II)) continue;
		_m = 3; goto P999; /* 0 */

		 /* PROC world */
	case 6: /* STATE 1 - line 8 "pan_in" - [printf('world\\n')] (0:0:0 - 1) */
		IfNotBlocked
		reached[1][1] = 1;
		Printf("world\n");
		_m = 3; goto P999; /* 0 */
	case 7: /* STATE 2 - line 10 "pan_in" - [-end-] (0:0:0 - 1) */
		IfNotBlocked
		reached[1][2] = 1;
		if (!delproc(1, II)) continue;
		_m = 3; goto P999; /* 0 */

		 /* PROC hello */
	case 8: /* STATE 1 - line 3 "pan_in" - [printf('hello\\n')] (0:0:0 - 1) */
		IfNotBlocked
		reached[0][1] = 1;
		Printf("hello\n");
		_m = 3; goto P999; /* 0 */
	case 9: /* STATE 2 - line 4 "pan_in" - [-end-] (0:0:0 - 1) */
		IfNotBlocked
		reached[0][2] = 1;
		if (!delproc(1, II)) continue;
		_m = 3; goto P999; /* 0 */
	case  _T5:	/* np_ */
		if (!((!(trpt->o_pm&4) && !(trpt->tau&128))))
			continue;
		/* else fall through */
	case  _T2:	/* true */
		_m = 3; goto P999;
#undef rand
	}

