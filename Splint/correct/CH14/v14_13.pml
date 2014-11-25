#define NS	2	/* nr of sessions in 3way call */

mtype = { offhook, digits, flash, onhook } /* flash added */
mtype = { iam, acm, anm, rel, rlc };
mtype = { idle, busy, setup, threeway };   /* states added */	

chan tpc      = [0] of { mtype };
chan rms[NS]  = [1] of { mtype };	/* added channel */
chan sess[NS] = [0] of { mtype };	/* added channel */

mtype s_state = idle;
