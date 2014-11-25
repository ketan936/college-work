#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mstring.h"

int a,b;

int fun()	/*@globals b;@*/
{
		
	return a;
}

int main(){
fun();
return 0;
}
