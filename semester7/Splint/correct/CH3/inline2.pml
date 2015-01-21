inline thisworks(x) {
	int y;

	y = x;
	printf("%d\n", y)
}
init {
	int a;
	a = 34;
	thisworks(a)
}
