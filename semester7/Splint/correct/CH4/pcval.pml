active proctype A()
{
	printf("%d\n", pc_value(_pid));
	printf("%d\n", pc_value(_pid));
	printf("%d\n", pc_value(_pid));
}

active proctype B()
{
	(pc_value(0) > 2);
	printf("ok\n")
}
