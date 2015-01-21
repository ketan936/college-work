	switch (t->back) {
	default: Uerror("bad return move");
	case  0: goto R999; /* nothing to undo */

		 /* PROC :init: */

	case 3: /* STATE 1 */
		;
		((P1 *)this)->proc = trpt->bup.oval;
		;
		goto R999;
;
		;
		
	case 5: /* STATE 4 */
		;
		((P1 *)this)->proc = trpt->bup.oval;
		;
		delproc(0, now._nr_pr-1);
		;
		goto R999;

	case 6: /* STATE 5 */
		;
	/* 0 */	((P1 *)this)->proc = trpt->bup.oval;
		;
		;
		goto R999;

	case 7: /* STATE 11 */
		;
		p_restor(II);
		;
		;
		goto R999;

		 /* PROC node */
;
		;
		
	case 9: /* STATE 2 */
		;
		_m = unsend(((P0 *)this)->out);
		;
		goto R999;

	case 10: /* STATE 3 */
		;
		XX = 1;
		unrecv(((P0 *)this)->in, XX-1, 0, 3, 1);
		unrecv(((P0 *)this)->in, XX-1, 1, ((int)((P0 *)this)->nr), 0);
		((P0 *)this)->nr = trpt->bup.oval;
		;
		;
		goto R999;
;
		;
		;
		;
		
	case 13: /* STATE 7 */
		;
		((P0 *)this)->neighbourR = trpt->bup.oval;
		_m = unsend(((P0 *)this)->out);
		;
		goto R999;

	case 14: /* STATE 10 */
		;
		((P0 *)this)->know_winner = trpt->bup.oval;
		;
		goto R999;

	case 15: /* STATE 11 */
		;
		_m = unsend(((P0 *)this)->out);
		;
		goto R999;

	case 16: /* STATE 15 */
		;
		_m = unsend(((P0 *)this)->out);
		;
		goto R999;

	case 17: /* STATE 18 */
		;
		XX = 1;
		unrecv(((P0 *)this)->in, XX-1, 0, 2, 1);
		unrecv(((P0 *)this)->in, XX-1, 1, ((int)((P0 *)this)->nr), 0);
		((P0 *)this)->nr = trpt->bup.oval;
		;
		;
		goto R999;

	case 18: /* STATE 21 */
		;
		((P0 *)this)->maximum = trpt->bup.ovals[2];
	/* 1 */	((P0 *)this)->maximum = trpt->bup.ovals[1];
	/* 0 */	((P0 *)this)->nr = trpt->bup.ovals[0];
		;
		;
		ungrab_ints(trpt->bup.ovals, 3);
		goto R999;

	case 19: /* STATE 22 */
		;
		_m = unsend(((P0 *)this)->out);
		;
		goto R999;

	case 20: /* STATE 24 */
		;
		((P0 *)this)->Active = trpt->bup.oval;
		;
		goto R999;

	case 21: /* STATE 28 */
		;
		_m = unsend(((P0 *)this)->out);
		;
		goto R999;

	case 22: /* STATE 31 */
		;
		XX = 1;
		unrecv(((P0 *)this)->in, XX-1, 0, 1, 1);
		unrecv(((P0 *)this)->in, XX-1, 1, ((int)((P0 *)this)->nr), 0);
		((P0 *)this)->nr = trpt->bup.oval;
		;
		;
		goto R999;

	case 23: /* STATE 32 */
		;
	/* 0 */	((P0 *)this)->mynumber = trpt->bup.oval;
		;
		;
		goto R999;
;
		;
		
	case 25: /* STATE 36 */
		;
		now.nr_leaders = trpt->bup.oval;
		;
		goto R999;
;
		;
		
	case 27: /* STATE 40 */
		;
	/* 0 */	((P0 *)this)->know_winner = trpt->bup.oval;
		;
		;
		goto R999;

	case 28: /* STATE 49 */
		;
		p_restor(II);
		;
		;
		goto R999;
	}

