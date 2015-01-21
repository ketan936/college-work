/* Peterson for 2 processes - modified - can deadlock! */

bool	flag[3];
byte	turn;
byte	cnt;

active proctype P1()
{
again:	flag[1] = true;
	turn = 1;
	!(flag[2]) ->

		cnt++; assert(cnt == 1); cnt--;

	flag[1] = false;
	goto again
}

active proctype P2()
{
again:	flag[2] = true;
	turn = 2;
	!(flag[1]) ->

		cnt++; assert(cnt == 1); cnt--;

	flag[2] = false;
	goto again
}
