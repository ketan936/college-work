#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void isPalindrome(char str[])
{
    int l = 0;
    int h = strlen(str)-1;
    while(h > l)
{
    if (str[l++] != str[h--])
    { 
        printf("not a palindrome \n");
        return;
    }
}
    printf("is a palindrome \n");
}
int main()
{
    isPalindrome("abba");
    isPalindrome("abbccbba");
    isPalindrome("geeks");
    return 0;
}


