mtype = { P, C, N };

mtype turn = P;
pid   who;

inline request(x, y, z) {
	atomic { x == y -> x = z; who = _pid }
}

inline release(x, y) {
	atomic { x = y; who = 0 }
}

active [2] proctype producer()
{
	do
	:: request(turn, P, N) ->
		printf("P%d\n", _pid);
		assert(who == _pid);
		release(turn, C)
	od
}

active [2] proctype consumer()
{
	do
	:: request(turn, C, N) ->
		printf("C%d\n", _pid);
		assert(who == _pid);
		release(turn, P)
	od
}
