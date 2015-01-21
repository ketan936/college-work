#define example(x, y) \
	y = a;	\
	x = b;	\
	assert(x)

init {
	int a, b;

	example(a,b)
}
