#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXLEN 1000
#define MOD 26

using namespace std;

char data[MAXLEN];

int key;

void encrypt_data()
{
    FILE *f = fopen("in_0.txt","r");
    FILE *fo = fopen("out_0.txt","w");
    int i;
    //printf("Enter Key value : ");
    //scanf("%d",&key);
    fscanf(f, "%d", &key);
    while(key<0)
    {
        key += MOD;
    }
    key %= MOD;
    //printf("Enter Data to encrypt : ");
    while(fscanf(f, "%s", data) != EOF)
    {
        char encrypted_data[MAXLEN];
        //printf(" %s\n",data);
        for(i=0; data[i] != '\0'; i++)
        {
            if(data[i] >= 'a' && data[i] <= 'z')
            {
                char temp = data[i];
                temp -= 'a';
                temp += key;
                //temp += 26;
                temp %= MOD;
                temp += 'a';
                encrypted_data[i] = temp;
            }
            else if(data[i] >= 'A' && data[i] <= 'Z')
            {
                char temp = data[i];
                temp -= 'A';
                temp += key;
                //temp += 26;
                temp %= MOD;
                temp += 'A';
                encrypted_data[i] = temp;
            }
            else
            {
                encrypted_data[i] = data[i];
            }
        }
        encrypted_data[i] = '\0';
        fprintf(fo,"%s\n",encrypted_data);
    }
    fclose(f);
    fclose(fo);
}

void decrypt_data(int key)
{
    FILE *f = fopen("out_0.txt","r");
    int i,k;
    char all_data[MAXLEN][MAXLEN];
    int j = 0;
    while(fscanf(f, "%s", data) != EOF)
    {
        strcpy(all_data[j], data);
        //printf("%s\n",all_data[j]);
        j++;
    }
    for(k=0;k<j;k++)
    {
        strcpy(data,all_data[k]);
        char encrypted_data[MAXLEN];
        for(i=0; data[i] != '\0'; i++)
        {
            if(data[i] >= 'a' && data[i] <= 'z')
            {
                char temp = data[i];
                temp -= 'a';
                temp -= key;
                temp += 26;
                temp %= MOD;
                temp += 'a';
               // temp %= MOD;
                encrypted_data[i] = temp;
            }
            else if(data[i] >= 'A' && data[i] <= 'Z')
            {
                char temp = data[i];
                temp -= 'A';
                temp -= key;
                temp += 26;
                temp %= MOD;
                temp += 'A';
                //temp %= MOD;
                encrypted_data[i] = temp;
            }
            else
            {
                encrypted_data[i] = data[i];
            }
        }
        encrypted_data[i] = '\0';
        printf("%s\n",encrypted_data);
    }
}

void brute_force_hack()
{
    FILE *f = fopen("out_0.txt","r");
    int i,key,k;
    char all_data[MAXLEN][MAXLEN];
    int j = 0;
    while(fscanf(f, "%s", data) != EOF)
    {
        strcpy(all_data[j], data);
        j++;
    }
    //printf("Enter Key value : ");
    for(key=0;key<26;key++)
    {
        for(k=0;k<j;k++)
        {
            strcpy(data,all_data[k]);
            char encrypted_data[MAXLEN];
            for(i=0; data[i] != '\0'; i++)
            {
                if(data[i] >= 'a' && data[i] <= 'z')
                {
                    char temp = data[i];
                    temp -= 'a';
                    temp -= key;
                    temp += 26;
                    temp %= MOD;
                    temp += 'a';
                    encrypted_data[i] = temp;
                }
                else if(data[i] >= 'A' && data[i] <= 'Z')
                {
                    char temp = data[i];
                    temp -= 'A';
                    temp -= key;
                    temp += 26;
                    temp %= MOD;
                    temp += 'A';
                    encrypted_data[i] = temp;
                }
                else
                {
                    encrypted_data[i] = data[i];
                }
            }
            encrypted_data[i] = '\0';
            printf("%s\n",encrypted_data);
        }
        printf("Is it readable? (y/n)");
        char ch;
        scanf(" %c",&ch);
        if(ch == 'y' || ch == 'Y')
        {
            printf("Cracked!\n");
            printf("Key is %d\n",key);
            break;
        }
        else
        {
            continue;
        }
    }
}

void frequency_hack()
{
    char goku[26] = {'e','t','a','o','i','n','s','h','r','d','l','u','c','m','w','f','y','g','p','b','v','k','x','j','q','z','\0'};
    int freq_cnt[26] = {0};
    FILE *f = fopen("out_0.txt","r");
    int i,key,k;
    char all_data[MAXLEN][MAXLEN];
    int j = 0;
    while(fscanf(f, "%s", data) != EOF)
    {
        int data_len = strlen(data);
        for(i=0;i<data_len;i++)
        {
            if(data[i] >= 'A' && data[i] <= 'Z')
            {
                data[i] += 32;
            }
            freq_cnt[data[i]-'a']++;
        }
        strcpy(all_data[j], data);
        j++;
    }
    int key_max = 0;
    int idx = 0;
    for(i=0;i<26;i++)
    {
        if(freq_cnt[i] > key_max)
        {
            key_max = freq_cnt[i];
            idx = i;
        }
    }
    for(int u = 0; goku[u] != '\0';u++)
    {
        key = idx - (goku[u] - 'a');
        key += MOD;
        key %= MOD;
        printf("key is : %d\n",key);
        for(k=0;k<j;k++)
        {
            strcpy(data,all_data[k]);
            char encrypted_data[MAXLEN];
            for(i=0; data[i] != '\0'; i++)
            {
                if(data[i] >= 'a' && data[i] <= 'z')
                {
                    char temp = data[i];
                    temp -= 'a';
                    temp -= key;
                    temp += 26;
                    temp %= MOD;
                    temp += 'a';
                   // temp %= MOD;
                    encrypted_data[i] = temp;
                }
                else if(data[i] >= 'A' && data[i] <= 'Z')
                {
                    char temp = data[i];
                    temp -= 'A';
                    temp -= key;
                    temp += 26;
                    temp %= MOD;
                    temp += 'A';
                    //temp %= MOD;
                    encrypted_data[i] = temp;
                }
                else
                {
                    encrypted_data[i] = data[i];
                }
            }
            encrypted_data[i] = '\0';
            printf("%s\n",encrypted_data);
        }
        printf("Is it readable? (y/n)");
        char ch;
        scanf(" %c",&ch);
        if(ch == 'y' || ch == 'Y')
        {
            printf("Cracked!\n");
            printf("Key is %d\n",key);
            break;
        }
        else
        {
            continue;
        }
    }
}

int main()
{
    while(1)
    {
        printf("[1] Encrypt Data\n[2] Decrypt Data\n[3] Hack Cipher\n[4] Frequency Hack\n[5] Exit\n");
        int choice;
        scanf(" %d",&choice);
        switch(choice)
        {
            case 1:
                encrypt_data();
            break;
            case 2:
                int k;
                printf("Enter Key: ");
                scanf(" %d",&k);
                decrypt_data(k);
            break;
            case 3:
                brute_force_hack();
            break;
            case 4:
                frequency_hack();
            break;
            case 5:
                return 0;
            break;
        }
    }
    return 0;
}
