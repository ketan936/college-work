#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

//jumps at 2*(key-1) - 1
char msg[1000];
char data[1000];
char cipher[1000];
char plain_text[1000];

void encrypt()
{
    scanf(" %[^\n]",msg);
    printf("%s\n",msg);
    int i = 0;
    int j = 0;
    for(i=0;msg[i] != '\0';i++)
    {
        if(msg[i] == ' ')
        {
            continue;
        }
        else if(msg[i] >= 'A' && msg[i] <= 'Z')
        {
            data[j] = msg[i] + 32;
            j++;
        }
        else
        {
            data[j] = msg[i];
            j++;
        }
    }
    data[j] = '\0';
    int data_len = strlen(data);
    int key;
    scanf(" %d",&key);
    if(key <= 1)
    {
    	printf("Key should not be <= 1\n");
    	return;
    }
    if(key >= data_len)
    {
        printf("Key cannot be more than data length\n");
        return;
    }
    int jump = 2*(key-1);
    int ap = key;
    while(ap < data_len)
    {
        ap += (key-1);
    }
    int z = data_len;
    while(z < ap)
    {
        data[z] = 'x';
        z++;
    }
    data[z] = '\0';
    printf("%s\n",data);
    data_len = strlen(data);
    int k = 0;
    for(i=0;i<key;i++)
    {
        if(i==0 || i==(key-1))
        {
            for(j=i;j<data_len;j+=jump)
            {
                cipher[k] = data[j];
                k++;
            }
        }
        else
        {
            for(j=0;j<data_len;j+=jump)
            {
                if((j-i) >= 0)
                {
                    cipher[k] = data[j-i];
                    k++;
                }
                if((j+i) < data_len)
                {
                    cipher[k] = data[j+i];
                    k++;
                }
            }
        }
    }
    cipher[k] = '\0';
    printf("%s\n",cipher);
}
void decrypt()
{
    int key,i,j;
    scanf(" %d",&key);
    int jump = 2*(key-1);
    int cipher_len = strlen(cipher);
    int k = 0;
    for(i=0;i<key;i++)
    {
        if(i==0 || i==(key-1))
        {
            for(j=i;j<cipher_len;j+=jump)
            {
                plain_text[j] = cipher[k];
                k++;
            }
        }
        else
        {
            for(j=0;j<cipher_len;j+=jump)
            {
                if((j-i) >= 0)
                {
                    plain_text[j-i] = cipher[k];
                    k++;
                }
                if((j+i) < cipher_len)
                {
                    plain_text[j+i] = cipher[k];
                    k++;
                }
            }
        }
    }
    plain_text[k] = '\0';
    int plen = strlen(plain_text);
    plen--;
    while(plain_text[plen] == 'x')
    {
    	plen--;
    }
    plen++;
    plain_text[plen] = '\0';
    printf("%s\n",plain_text);
}
int main()
{
    while(1)
    {
        int choice;
        printf("[0] Encrypt\n[1] Decrypt\n");
        printf("Enter Choice: ");
        scanf(" %d",&choice);
        switch(choice)
        {
            case 0:
                encrypt();
            break;
            case 1:
                decrypt();
            break;
            case 3:
                return 0;
            break;
        }
    }
    return 0;
}
