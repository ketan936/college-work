/* Peterson for 2 processes */

bool	turn, flag[2];
byte	cnt;

active [2] proctype P1()
{	pid i, j;

	i = _pid;
	j = 1 - _pid;

again:	flag[i] = true;
	turn = i;
	!(flag[j] && turn == i) ->

		cnt++; assert(cnt == 1); cnt--;

	flag[i] = false;
	goto again
}

/* deleting "turn == i" can lead to deadlock:
  1:    proc  1 (P2) line  21 "peters2a.pml" (state 1)  [flag[1] = true]
  2:    proc  1 (P2) line  22 "peters2a.pml" (state 2)  [turn = 1]
  3:    proc  0 (P1) line   9 "peters2a.pml" (state 1)  [flag[0] = true]
  4:    proc  0 (P1) line  10 "peters2a.pml" (state 2)  [turn = 0]

 */
