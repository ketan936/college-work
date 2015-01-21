#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mstring.h"

int *t;

void fun(char *s,char *t){
	strcpy(s,t);	
	return ;
}

int main(){
fun("Hello","Hii");
return 0;
}
