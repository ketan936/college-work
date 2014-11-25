#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mstring.h"

void fun(int *a,int *b)	/*@modifies *b @*/
{
	*a=*b;
	return ;
}

int main(){
int c=10,d=20;
int *a;
int *b;
a=&c;
b=&d;
fun(a,b);
return 0;
}
