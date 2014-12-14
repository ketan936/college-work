#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int getMaxOccuringChar(char*c)
{
    int arr[256] ={0};
    int i;
    int maxcount = 0;
    for (i=0; i<strlen(c);i++)
    {
        arr[c[i]]++;
        if (arr[c[i]] > arr[maxcount])
            maxcount = c[i];
        
    }
    return maxcount;
}
int main()
{
  char str[] = "saiaaaaaaaaaaample string";
  printf("%c", getMaxOccuringChar(str));
 
  getchar();
  return 0;
}
