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
	case 3: /* STATE 1 - line 75 "pan_in" - [proc = 1] (0:0:1 - 1) */
		IfNotBlocked
		reached[1][1] = 1;
		(trpt+1)->bup.oval = ((int)((P1 *)this)->proc);
		((P1 *)this)->proc = 1;
#ifdef VAR_RANGES
		logval(":init::proc", ((int)((P1 *)this)->proc));
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 4: /* STATE 2 - line 77 "pan_in" - [((proc<=5))] (0:0:0 - 1) */
		IfNotBlocked
		reached[1][2] = 1;
		if (!((((int)((P1 *)this)->proc)<=5)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 5: /* STATE 3 - line 78 "pan_in" - [(run node(q[(proc-1)],q[(proc%5)],((((5+3)-proc)%5)+1)))] (7:0:1 - 1) */
		IfNotBlocked
		reached[1][3] = 1;
		if (!(addproc(0, now.q[ Index((((int)((P1 *)this)->proc)-1), 5) ], now.q[ Index((((int)((P1 *)this)->proc)%5), 5) ], ((((5+3)-((int)((P1 *)this)->proc))%5)+1))))
			continue;
		/* merge: proc = (proc+1)(0, 4, 7) */
		reached[1][4] = 1;
		(trpt+1)->bup.oval = ((int)((P1 *)this)->proc);
		((P1 *)this)->proc = (((int)((P1 *)this)->proc)+1);
#ifdef VAR_RANGES
		logval(":init::proc", ((int)((P1 *)this)->proc));
#endif
		;
		/* merge: .(goto)(0, 8, 7) */
		reached[1][8] = 1;
		;
		_m = 3; goto P999; /* 2 */
	case 6: /* STATE 5 - line 80 "pan_in" - [((proc>5))] (9:0:1 - 1) */
		IfNotBlocked
		reached[1][5] = 1;
		if (!((((int)((P1 *)this)->proc)>5)))
			continue;
		/* dead 1: proc */  (trpt+1)->bup.oval = ((P1 *)this)->proc;
#ifdef HAS_CODE
		if (!readtrail)
#endif
			((P1 *)this)->proc = 0;
		/* merge: goto :b1(0, 6, 9) */
		reached[1][6] = 1;
		;
		_m = 3; goto P999; /* 1 */
	case 7: /* STATE 11 - line 84 "pan_in" - [-end-] (0:0:0 - 1) */
		IfNotBlocked
		reached[1][11] = 1;
		if (!delproc(1, II)) continue;
		_m = 3; goto P999; /* 0 */

		 /* PROC node */
	case 8: /* STATE 1 - line 22 "pan_in" - [printf('MSC: %d\\n',mynumber)] (0:0:0 - 1) */
		IfNotBlocked
		reached[0][1] = 1;
		Printf("MSC: %d\n", ((int)((P0 *)this)->mynumber));
		_m = 3; goto P999; /* 0 */
	case 9: /* STATE 2 - line 23 "pan_in" - [out!one,mynumber] (0:0:0 - 1) */
		IfNotBlocked
		reached[0][2] = 1;
		
#ifndef XUSAFE
		if (q_claim[((P0 *)this)->out]&2) q_S_check(((P0 *)this)->out, II);
#endif
		if (q_full(((P0 *)this)->out))
			continue;
#ifdef HAS_CODE
		if (readtrail && gui) {
			char simtmp[32];
			sprintf(simvals, "%d!", ((P0 *)this)->out);
		sprintf(simtmp, "%d", 3); strcat(simvals, simtmp);		strcat(simvals, ",");
		sprintf(simtmp, "%d", ((int)((P0 *)this)->mynumber)); strcat(simvals, simtmp);		}
#endif
		
		qsend(((P0 *)this)->out, 0, 3, ((int)((P0 *)this)->mynumber));
		_m = 2; goto P999; /* 0 */
	case 10: /* STATE 3 - line 25 "pan_in" - [in?one,nr] (0:0:1 - 1) */
		reached[0][3] = 1;
		
#ifndef XUSAFE
		if (q_claim[((P0 *)this)->in]&1) q_R_check(((P0 *)this)->in, II);
#endif
		if (q_len(((P0 *)this)->in) == 0) continue;

		XX=1;
		if (3 != qrecv(((P0 *)this)->in, 0, 0, 0)) continue;
		(trpt+1)->bup.oval = ((int)((P0 *)this)->nr);
		;
		((P0 *)this)->nr = qrecv(((P0 *)this)->in, XX-1, 1, 1);
#ifdef VAR_RANGES
		logval("node:nr", ((int)((P0 *)this)->nr));
#endif
		;
		
#ifdef HAS_CODE
		if (readtrail && gui) {
			char simtmp[32];
			sprintf(simvals, "%d?", ((P0 *)this)->in);
		sprintf(simtmp, "%d", 3); strcat(simvals, simtmp);		strcat(simvals, ",");
		sprintf(simtmp, "%d", ((int)((P0 *)this)->nr)); strcat(simvals, simtmp);		}
#endif
		;
		_m = 4; goto P999; /* 0 */
	case 11: /* STATE 4 - line 27 "pan_in" - [(Active)] (0:0:0 - 1) */
		IfNotBlocked
		reached[0][4] = 1;
		if (!(((int)((P0 *)this)->Active)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 12: /* STATE 5 - line 29 "pan_in" - [((nr!=maximum))] (0:0:0 - 1) */
		IfNotBlocked
		reached[0][5] = 1;
		if (!((((int)((P0 *)this)->nr)!=((int)((P0 *)this)->maximum))))
			continue;
		_m = 3; goto P999; /* 0 */
	case 13: /* STATE 6 - line 30 "pan_in" - [out!two,nr] (46:0:1 - 1) */
		IfNotBlocked
		reached[0][6] = 1;
		
#ifndef XUSAFE
		if (q_claim[((P0 *)this)->out]&2) q_S_check(((P0 *)this)->out, II);
#endif
		if (q_full(((P0 *)this)->out))
			continue;
#ifdef HAS_CODE
		if (readtrail && gui) {
			char simtmp[32];
			sprintf(simvals, "%d!", ((P0 *)this)->out);
		sprintf(simtmp, "%d", 2); strcat(simvals, simtmp);		strcat(simvals, ",");
		sprintf(simtmp, "%d", ((int)((P0 *)this)->nr)); strcat(simvals, simtmp);		}
#endif
		
		qsend(((P0 *)this)->out, 0, 2, ((int)((P0 *)this)->nr));
		/* merge: neighbourR = nr(0, 7, 46) */
		reached[0][7] = 1;
		(trpt+1)->bup.oval = ((int)((P0 *)this)->neighbourR);
		((P0 *)this)->neighbourR = ((int)((P0 *)this)->nr);
#ifdef VAR_RANGES
		logval("node:neighbourR", ((int)((P0 *)this)->neighbourR));
#endif
		;
		/* merge: .(goto)(0, 13, 46) */
		reached[0][13] = 1;
		;
		/* merge: .(goto)(0, 17, 46) */
		reached[0][17] = 1;
		;
		/* merge: .(goto)(0, 47, 46) */
		reached[0][47] = 1;
		;
		_m = 2; goto P999; /* 4 */
	case 14: /* STATE 9 - line 34 "pan_in" - [assert((nr==5))] (0:11:1 - 1) */
		IfNotBlocked
		reached[0][9] = 1;
		assert((((int)((P0 *)this)->nr)==5), "(nr==5)", II, tt, t);
		/* merge: know_winner = 1(11, 10, 11) */
		reached[0][10] = 1;
		(trpt+1)->bup.oval = ((int)((P0 *)this)->know_winner);
		((P0 *)this)->know_winner = 1;
#ifdef VAR_RANGES
		logval("node:know_winner", ((int)((P0 *)this)->know_winner));
#endif
		;
		_m = 3; goto P999; /* 1 */
	case 15: /* STATE 11 - line 36 "pan_in" - [out!winner,nr] (0:0:0 - 1) */
		IfNotBlocked
		reached[0][11] = 1;
		
#ifndef XUSAFE
		if (q_claim[((P0 *)this)->out]&2) q_S_check(((P0 *)this)->out, II);
#endif
		if (q_full(((P0 *)this)->out))
			continue;
#ifdef HAS_CODE
		if (readtrail && gui) {
			char simtmp[32];
			sprintf(simvals, "%d!", ((P0 *)this)->out);
		sprintf(simtmp, "%d", 1); strcat(simvals, simtmp);		strcat(simvals, ",");
		sprintf(simtmp, "%d", ((int)((P0 *)this)->nr)); strcat(simvals, simtmp);		}
#endif
		
		qsend(((P0 *)this)->out, 0, 1, ((int)((P0 *)this)->nr));
		_m = 2; goto P999; /* 0 */
	case 16: /* STATE 15 - line 39 "pan_in" - [out!one,nr] (0:0:0 - 1) */
		IfNotBlocked
		reached[0][15] = 1;
		
#ifndef XUSAFE
		if (q_claim[((P0 *)this)->out]&2) q_S_check(((P0 *)this)->out, II);
#endif
		if (q_full(((P0 *)this)->out))
			continue;
#ifdef HAS_CODE
		if (readtrail && gui) {
			char simtmp[32];
			sprintf(simvals, "%d!", ((P0 *)this)->out);
		sprintf(simtmp, "%d", 3); strcat(simvals, simtmp);		strcat(simvals, ",");
		sprintf(simtmp, "%d", ((int)((P0 *)this)->nr)); strcat(simvals, simtmp);		}
#endif
		
		qsend(((P0 *)this)->out, 0, 3, ((int)((P0 *)this)->nr));
		_m = 2; goto P999; /* 0 */
	case 17: /* STATE 18 - line 42 "pan_in" - [in?two,nr] (0:0:1 - 1) */
		reached[0][18] = 1;
		
#ifndef XUSAFE
		if (q_claim[((P0 *)this)->in]&1) q_R_check(((P0 *)this)->in, II);
#endif
		if (q_len(((P0 *)this)->in) == 0) continue;

		XX=1;
		if (2 != qrecv(((P0 *)this)->in, 0, 0, 0)) continue;
		(trpt+1)->bup.oval = ((int)((P0 *)this)->nr);
		;
		((P0 *)this)->nr = qrecv(((P0 *)this)->in, XX-1, 1, 1);
#ifdef VAR_RANGES
		logval("node:nr", ((int)((P0 *)this)->nr));
#endif
		;
		
#ifdef HAS_CODE
		if (readtrail && gui) {
			char simtmp[32];
			sprintf(simvals, "%d?", ((P0 *)this)->in);
		sprintf(simtmp, "%d", 2); strcat(simvals, simtmp);		strcat(simvals, ",");
		sprintf(simtmp, "%d", ((int)((P0 *)this)->nr)); strcat(simvals, simtmp);		}
#endif
		;
		_m = 4; goto P999; /* 0 */
/* STATE 19 - line 44 "pan_in" - [(Active)] (0:0 - 1) same as 11 (0:0 - 1) */
	case 18: /* STATE 20 - line 46 "pan_in" - [(((neighbourR>nr)&&(neighbourR>maximum)))] (22:0:3 - 1) */
		IfNotBlocked
		reached[0][20] = 1;
		if (!(((((int)((P0 *)this)->neighbourR)>((int)((P0 *)this)->nr))&&(((int)((P0 *)this)->neighbourR)>((int)((P0 *)this)->maximum)))))
			continue;
		/* dead 1: nr */  (trpt+1)->bup.ovals = grab_ints(3);
		(trpt+1)->bup.ovals[0] = ((P0 *)this)->nr;
#ifdef HAS_CODE
		if (!readtrail)
#endif
			((P0 *)this)->nr = 0;
		/* dead 1: maximum */  (trpt+1)->bup.ovals[1] = ((P0 *)this)->maximum;
#ifdef HAS_CODE
		if (!readtrail)
#endif
			((P0 *)this)->maximum = 0;
		/* merge: maximum = neighbourR(0, 21, 22) */
		reached[0][21] = 1;
		(trpt+1)->bup.ovals[2] = ((int)((P0 *)this)->maximum);
		((P0 *)this)->maximum = ((int)((P0 *)this)->neighbourR);
#ifdef VAR_RANGES
		logval("node:maximum", ((int)((P0 *)this)->maximum));
#endif
		;
		_m = 3; goto P999; /* 1 */
	case 19: /* STATE 22 - line 48 "pan_in" - [out!one,neighbourR] (0:0:0 - 1) */
		IfNotBlocked
		reached[0][22] = 1;
		
#ifndef XUSAFE
		if (q_claim[((P0 *)this)->out]&2) q_S_check(((P0 *)this)->out, II);
#endif
		if (q_full(((P0 *)this)->out))
			continue;
#ifdef HAS_CODE
		if (readtrail && gui) {
			char simtmp[32];
			sprintf(simvals, "%d!", ((P0 *)this)->out);
		sprintf(simtmp, "%d", 3); strcat(simvals, simtmp);		strcat(simvals, ",");
		sprintf(simtmp, "%d", ((int)((P0 *)this)->neighbourR)); strcat(simvals, simtmp);		}
#endif
		
		qsend(((P0 *)this)->out, 0, 3, ((int)((P0 *)this)->neighbourR));
		_m = 2; goto P999; /* 0 */
	case 20: /* STATE 24 - line 50 "pan_in" - [Active = 0] (0:0:1 - 1) */
		IfNotBlocked
		reached[0][24] = 1;
		(trpt+1)->bup.oval = ((int)((P0 *)this)->Active);
		((P0 *)this)->Active = 0;
#ifdef VAR_RANGES
		logval("node:Active", ((int)((P0 *)this)->Active));
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 21: /* STATE 28 - line 53 "pan_in" - [out!two,nr] (0:0:0 - 1) */
		IfNotBlocked
		reached[0][28] = 1;
		
#ifndef XUSAFE
		if (q_claim[((P0 *)this)->out]&2) q_S_check(((P0 *)this)->out, II);
#endif
		if (q_full(((P0 *)this)->out))
			continue;
#ifdef HAS_CODE
		if (readtrail && gui) {
			char simtmp[32];
			sprintf(simvals, "%d!", ((P0 *)this)->out);
		sprintf(simtmp, "%d", 2); strcat(simvals, simtmp);		strcat(simvals, ",");
		sprintf(simtmp, "%d", ((int)((P0 *)this)->nr)); strcat(simvals, simtmp);		}
#endif
		
		qsend(((P0 *)this)->out, 0, 2, ((int)((P0 *)this)->nr));
		_m = 2; goto P999; /* 0 */
	case 22: /* STATE 31 - line 55 "pan_in" - [in?winner,nr] (0:0:1 - 1) */
		reached[0][31] = 1;
		
#ifndef XUSAFE
		if (q_claim[((P0 *)this)->in]&1) q_R_check(((P0 *)this)->in, II);
#endif
		if (q_len(((P0 *)this)->in) == 0) continue;

		XX=1;
		if (1 != qrecv(((P0 *)this)->in, 0, 0, 0)) continue;
		(trpt+1)->bup.oval = ((int)((P0 *)this)->nr);
		;
		((P0 *)this)->nr = qrecv(((P0 *)this)->in, XX-1, 1, 1);
#ifdef VAR_RANGES
		logval("node:nr", ((int)((P0 *)this)->nr));
#endif
		;
		
#ifdef HAS_CODE
		if (readtrail && gui) {
			char simtmp[32];
			sprintf(simvals, "%d?", ((P0 *)this)->in);
		sprintf(simtmp, "%d", 1); strcat(simvals, simtmp);		strcat(simvals, ",");
		sprintf(simtmp, "%d", ((int)((P0 *)this)->nr)); strcat(simvals, simtmp);		}
#endif
		;
		_m = 4; goto P999; /* 0 */
	case 23: /* STATE 32 - line 57 "pan_in" - [((nr!=mynumber))] (43:0:1 - 1) */
		IfNotBlocked
		reached[0][32] = 1;
		if (!((((int)((P0 *)this)->nr)!=((int)((P0 *)this)->mynumber))))
			continue;
		/* dead 1: mynumber */  (trpt+1)->bup.oval = ((P0 *)this)->mynumber;
#ifdef HAS_CODE
		if (!readtrail)
#endif
			((P0 *)this)->mynumber = 0;
		/* merge: printf('MSC: LOST\\n')(0, 33, 43) */
		reached[0][33] = 1;
		Printf("MSC: LOST\n");
		/* merge: .(goto)(0, 39, 43) */
		reached[0][39] = 1;
		;
		_m = 3; goto P999; /* 2 */
	case 24: /* STATE 35 - line 60 "pan_in" - [printf('MSC: LEADER\\n')] (0:0:0 - 1) */
		IfNotBlocked
		reached[0][35] = 1;
		Printf("MSC: LEADER\n");
		_m = 3; goto P999; /* 0 */
	case 25: /* STATE 36 - line 61 "pan_in" - [nr_leaders = (nr_leaders+1)] (0:0:1 - 1) */
		IfNotBlocked
		reached[0][36] = 1;
		(trpt+1)->bup.oval = ((int)now.nr_leaders);
		now.nr_leaders = (((int)now.nr_leaders)+1);
#ifdef VAR_RANGES
		logval("nr_leaders", ((int)now.nr_leaders));
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 26: /* STATE 37 - line 62 "pan_in" - [assert((nr_leaders==1))] (0:0:0 - 1) */
		IfNotBlocked
		reached[0][37] = 1;
		assert((((int)now.nr_leaders)==1), "(nr_leaders==1)", II, tt, t);
		_m = 3; goto P999; /* 0 */
	case 27: /* STATE 40 - line 65 "pan_in" - [(know_winner)] (0:0:1 - 1) */
		IfNotBlocked
		reached[0][40] = 1;
		if (!(((int)((P0 *)this)->know_winner)))
			continue;
		/* dead 1: know_winner */  (trpt+1)->bup.oval = ((P0 *)this)->know_winner;
#ifdef HAS_CODE
		if (!readtrail)
#endif
			((P0 *)this)->know_winner = 0;
		_m = 3; goto P999; /* 0 */
/* STATE 42 - line 66 "pan_in" - [out!winner,nr] (0:0 - 1) same as 15 (0:0 - 1) */
	case 28: /* STATE 49 - line 70 "pan_in" - [-end-] (0:0:0 - 5) */
		IfNotBlocked
		reached[0][49] = 1;
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

