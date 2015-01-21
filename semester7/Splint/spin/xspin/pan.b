	switch (t->back) {
	default: Uerror("bad return move");
	case  0: goto R999; /* nothing to undo */

		 /* PROC :init: */

	case 3: /* STATE 1 */
		;
		;
		delproc(0, now._nr_pr-1);
		;
		goto R999;

	case 4: /* STATE 2 */
		;
		;
		delproc(0, now._nr_pr-1);
		;
		goto R999;

	case 5: /* STATE 3 */
		;
		p_restor(II);
		;
		;
		goto R999;

		 /* PROC world */
;
		;
		
	case 7: /* STATE 2 */
		;
		p_restor(II);
		;
		;
		goto R999;

		 /* PROC hello */
;
		;
		
	case 9: /* STATE 2 */
		;
		p_restor(II);
		;
		;
		goto R999;
	}

