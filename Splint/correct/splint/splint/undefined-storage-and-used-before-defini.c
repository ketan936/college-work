#include <stdio.h>
#include <stdlib.h>

extern int setval (int *x);

void fun(/*@out@*/int *x){
	printf("%d",*x);
}

int main(){
fun(malloc(4));
return 0;
}
