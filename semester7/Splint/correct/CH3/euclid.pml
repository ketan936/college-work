proctype Euclid(int x, y)
{
	do
	:: (x >  y) -> x = x - y
	:: (x <  y) -> y = y - x
	:: (x == y) -> goto done
	od;
done:
	printf("answer: %d\n", x)
}

init { run Euclid(36, 12) }
