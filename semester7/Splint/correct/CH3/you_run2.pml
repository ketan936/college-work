proctype you_run(byte x)
{
	printf("x = %d, pid = %d\n", x, _pid)
}

#if 1
	/* leaving pids implicit */
init {
	run you_run(0);
	run you_run(1)
}

#else
	/* storing pids in local vars */
init {	pid p0, p1;

	p0 = run you_run(0);
	p1 = run you_run(1);
	printf("pids: %d and %d\n", p0, p1)
}

#endif
