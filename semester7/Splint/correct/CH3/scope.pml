init {
	/* x declared in outer block */
	int x;
	{	/* y declared in inner block */
		int y;
		printf("x = %d, y = %d\n", x, y);
		x++;
		y++;
	}
	/* y remains in scope */
	printf("x = %d, y = %d\n", x, y);
}
