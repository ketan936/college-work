bool	toggle = true;
int	cnt;

active proctype A() provided (toggle == true)
{
	do
	:: cnt++; printf("A: cnt=%d\n", cnt); toggle = false
	od
}

active proctype B() provided (toggle == false)
{
	do
	:: cnt--; printf("B: cnt=%d\n", cnt); toggle = true
	od
}
