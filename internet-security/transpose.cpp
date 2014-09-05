#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
char msg[1000];
char data[1000];
char key[1000];
char cipher[1000];
char decipher[1000];

void encrypt()
{
	int i;
	printf("Enter Message: ");
	scanf(" %[^\n]",msg);
	printf("Enter Key: ");
	encrypt_function:
	scanf(" %[^\n]",key);  //key len cannot be 1
	int key_length = strlen(key);
	if(key_length <= 1)
	{
		printf("Key Length should be > 1. Enter Key again: ");
		goto encrypt_function;
	}
	vector < pair<char,int> > mykey;
	for(i=0;i<key_length;i++)
	{
		mykey.push_back(make_pair(key[i],i));
	}
	
	sort(mykey.begin(),mykey.end());
	
	for(i=0;i<mykey.size();i++)
	{
		printf(" %c %d\n",mykey[i].first,mykey[i].second);
	}

	i = 0;
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
    int data_length = strlen(data);
    printf("%s\n",data);

    int upto = data_length%key_length;
    if(upto != 0)
	{
		upto = key_length - upto;
	}
    i = data_length;
    for(j=0;j<upto;j++)
    {
    	data[i] = 'x';
    	i++;
    }
    data[i] = '\0';
    data_length = strlen(data);
    printf("%s\n",data);
    int z = 0;
    for(i=0;i<mykey.size();i++)
    {
    	j = mykey[i].second;
    	for(int k=j;k<data_length;k+=key_length)
    	{
    		cipher[z] = data[k];
    		z++;
    	}
    }
    cipher[z] = '\0';
    printf("%s\n",cipher);
}

void decrypt()
{
	int i,j;
	printf("Enter Key to Decrypt: ");
	decrypt_function:
	scanf(" %[^\n]",key);  //key len cannot be 1
	int key_length = strlen(key);
	if(key_length <= 1)
	{
		printf("Key Length should be > 1. Enter Key again: ");
		goto decrypt_function;
	}
	vector < pair<char,int> > mykey;
	for(i=0;i<key_length;i++)
	{
		mykey.push_back(make_pair(key[i],i));
	}
	sort(mykey.begin(),mykey.end());
	int z = 0;
	int data_length = strlen(cipher);
    for(i=0;i<mykey.size();i++)
    {
    	j = mykey[i].second;
    	for(int k=j;k<data_length;k+=key_length)
    	{
    		decipher[k] = cipher[z];
    		z++;
    	}
    }
    decipher[z] = '\0';
    printf("%s\n",decipher);
    int plen = strlen(decipher);
    plen--;
    while(decipher[plen] == 'x')
    {
    	plen--;
    }
    plen++;
    decipher[plen] = '\0';
    printf("%s\n",decipher);
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
