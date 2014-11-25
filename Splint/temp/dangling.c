
#include <stdlib.h>
extern /*@only@*/ int *glob;/*@only@*/ 
int *f (int *x, int *y,int *z)
{
int *m = (int *)malloc (sizeof (int));
glob = y;
free(x);
}

