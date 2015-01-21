typedef Field {
        short f = 3;
        byte  g
};

typedef Record {
        byte a[3];
        int fld1;
        Field fld2;
        chan p[3];
        bit b
};

proctype me(Field z) {
	z.g = 12
}

init {
	Record goo;
	Field  foo;

	run me(foo)
}
