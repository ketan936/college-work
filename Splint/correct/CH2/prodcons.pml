mtype = { P, C };

mtype turn = P;

active proctype producer()
{
	do
	:: (turn == P) ->
		printf("Produce\n");
		turn = C
	od
}

active proctype consumer()
{
	do
	:: (turn == C) ->
		printf("Consume\n");
		turn = P
	od
}
