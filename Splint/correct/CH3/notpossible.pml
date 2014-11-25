proctype A()
{
	_pid > 0 && - run A();
	printf("A\n")
}

init {
	!run A()
}
