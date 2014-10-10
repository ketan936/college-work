#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
using namespace std;

int main()
{
	int i,pos,j;
	char c;
	int sw;
	printf("\n1.for ciphering");
	printf("\n2.for decihering");
	scanf("\n%d",&sw);

	switch(sw)
	{

		case 1:
		{

			FILE *fp;
			fp=fopen("plain.txt","r");

			if(fp == NULL)
			{
				printf("No such file exist");

			}

			else

			// Set the pointer to the end
			fseek(fp, 0, SEEK_END);
			pos=ftell(fp);
			printf("pos:%d\n",pos);

			char p[pos];
			char k[50];

			printf("\nEnter the Key. ");
			scanf("%s",k);
			int keylen=strlen(k);

			fclose(fp);
			fp=fopen("plain.txt","r");
			i=0;
			c=fgetc(fp);
			while(c!=EOF)
			{
				printf("%d\n",i);
				if(c!=' ' && c!='\n')
				{
					p[i]=tolower(c);
					i++;
				}
				c=fgetc(fp);

			}
			p[i]='\0';
			printf("\nPlain text:%s ",p);
			int plainlen=strlen(p);
			fclose(fp);
			char frmkey[plainlen];
//------------------------CYPHERING------------------------------------

			for(i=0;i<plainlen;)
			{
				for(j=0;j<keylen && i<plainlen;j++)
				{
					frmkey[i]=k[j];
					i++;
				}

			}
			frmkey[i]='\0';
			printf("formkey:%s",frmkey);

			FILE *fq;
			fq=fopen("cipher.txt","w");
			char cyp,key;
			int cypint;
			for(i=0;i<plainlen;i++)
			{
				key=frmkey[i]-97;
				cypint=p[i]+key;
				if(cypint>122)
				{
					cypint=cypint-26;
				}
				cyp=cypint;
				fputc(cyp,fq);
			}
			fclose(fq);
		}break;

		case 2:
		{
			FILE *fp;
			fp=fopen("cipher.txt","r");

			if(fp == NULL)
			{
				printf("No such file exist");

			}

			else

			// Set the pointer to the end
			fseek(fp, 0, SEEK_END);
			pos=ftell(fp);
			//printf("pos:%d\n",pos);

			char p[pos];
			char k[50];

			printf("\nEnter the Key. ");
			scanf("%s",k);
			int keylen=strlen(k);

			fclose(fp);
			fp=fopen("cipher.txt","r");
			i=0;
			c=fgetc(fp);
			while(c!=EOF)
			{
				printf("%d\n",i);
				if(c!=' ' && c!='\n')
				{
					p[i]=tolower(c);
					i++;
				}
				c=fgetc(fp);

			}
			p[i]='\0';
			printf("\nCipher text:%s ",p);
			int plainlen=strlen(p);
			fclose(fp);
			char frmkey[plainlen];
//------------------------DeCiPHERING------------------------------------

			for(i=0;i<plainlen;)
			{
				for(j=0;j<keylen && i<plainlen;j++)
				{
					frmkey[i]=k[j];
					i++;
				}

			}
			frmkey[i]='\0';
			printf("formkey:%s",frmkey);

			FILE *fq;
			fq=fopen("decipher.txt","w");
			char cyp,key;
			int cypint;
			for(i=0;i<plainlen;i++)
			{
				key=frmkey[i]-97;
				cypint=p[i]-key;
				if(cypint<97)
				{
					cypint=cypint+26;
				}
				cyp=cypint;
				fputc(cyp,fq);
			}
			fclose(fq);

		}break;
	} //switch
}

