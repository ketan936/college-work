#define freelock(x)	x = 0
#define waitlock(x)	(x == 0)
#define spinlock(x)	atomic { waitlock(x) -> x = 1 }

inline wakeup(x) {
	spinlock(sq);
	i = 0;
	do :: i < N ->
		if
		:: pstate[i] == Wakeme ->
			pstate[i] = Running
		:: else	-> i++
		fi
	   :: else -> break
	od;
	freelock(sq)
}
inline sleepl(y, x) {
	spinlock(sq);
	freelock(lk);
	pstate[_pid] = Wakeme;
	freelock(sq);
	(pstate[_pid] == Running);
	spinlock(lk)
}
