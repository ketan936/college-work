#include<stdio.h>
char firstchar1 (/*@null@*/char *s)
{
   return *s;
}
/*char firstchar2 (char *s)
{
if (s == NULL) return '\0';
return *s;
}*/

int main()
{
  char *ptr;
  firstchar1(ptr);
 // ch=firstchar2(ptr);
 // return 0;
}
