/* Raynal [1986], p. 32 */

#if 1
bool turn;
bool flag[2];
byte cnt;

active [2] proctype mutex()	/* Dekker's 1965 algorithm */
{	pid i, j;

	i = _pid;
	j = 1 - _pid;
again:
	flag[i] = true;
#ifdef DORAN
	/* Doran and Thomas [1980] */
	if
#else
	do	/* can be 'if' - says Doran&Thomas */
#endif
	:: flag[j] ->
		if
		:: turn == j ->
			flag[i] = false;
			!(turn == j);
			flag[i] = true
		:: else
		fi
	:: else ->
		break
#ifdef DORAN
	fi;
#else
	od;
#endif

	cnt++;
	assert(cnt == 1);	/* critical section */
	cnt--;

	turn = j;
	flag[i] = false;
	goto again
}

#else

bool flag[2];
bool after_you[2];
bool turn;

int cnt;

active [2] proctype mutex()
{	int i, j;

	i = _pid;
	j = 1 - _pid;
again:
	flag[i] = true;
	if
	:: flag[j] ->
		after_you[i] = true;
		!(flag[j] && (turn == j || after_you[j] == false));
		after_you[i] = false
	:: else
	fi;

	cnt++;
	assert(cnt == 1);	/* critical section */
	cnt--;

	turn = j;
	flag[i] = false;
	goto again
}
#endif
