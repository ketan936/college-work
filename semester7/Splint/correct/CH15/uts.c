#if 0
   CH15 uts sleep-wakeup routines example

   this is a sample C implementation to illustrate how
   a Spin model can be extracted also mechanically from
   the C implementation below, using the test harness
   definition in file: uts.prx:

   	modex uts.prx

   the user proctype that is written into file _modex_user.spn
   needs to be adjusted by adding the desired number of processes
   (3) as a suffix to the active declaration:

   	active [3] proctype user()

   the verifier can then be compiled and a basic run can be
   performed by executing the shell script:

   	sh _modex_.run

   (see the script for the steps taken)

#endif

typedef struct R {
	int lock;
	int wanted;
} R;

R resource;
R *r = &resource;
int	lk, sq;

void
user(void)
{	int i;

	for (;;)
	{	spinlock(&lk);
		while (r->lock) {
			r->wanted = 1;
			sleepl(r, &lk);
		}
		r->lock = 1;
		freelock(&lk);

		/* use resource */

		r->lock = 0;
		waitlock(&lk);
		if (r->wanted) {
			r->wanted = 0;
			waitlock(&lk);
			wakeup(r);
		}
	}
}
