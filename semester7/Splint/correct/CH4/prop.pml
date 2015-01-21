byte x = 1;

init {

	do
	:: x = 0
	:: x = 2
	od
}

#define p	(x != 0)

#ifdef PHI

never {    /* []p */
accept:
	do
        :: (p)
        od
}

#else

never {    /* ![]p */
	do
        :: !p ->break
        :: true
        od
}

#endif
