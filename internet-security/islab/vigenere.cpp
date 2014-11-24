#include<bits/stdc++.h>
using namespace std;

string readfile(char *filename)
{
	string str="",temp="";
	ifstream input;
	input.open(filename,ios::in);
	
	while(input>>temp)
	{
		str.append(temp);
	}
	input.close();
	return str;	
}
string filterOut(string str)
{
	string a="";
	for(int i=0;i<str.length();i++)
	{
		if(isalpha(str[i]) || isdigit(str[i]))
			a.push_back(tolower(str[i]));
	}
	return a;
}
void writefile(string str,char *filename)
{
	ofstream output;
	output.open(filename,ios::out);
	output<<str;
	output.close();	
	return;
}
int main(int argc,char *argv[])
{	
	char outputfile[101],inputfile[101];
	int length_file,length_encrypted,length_key;

	while(1)
	{
		
		
		printf("---------------------------------------\nMENU:\n1. Encrypt a file\n2. Decrypt a file\n3. Exit\nEnter your choice: ");
		int choice,i;
		
		cin>>choice;
		switch(choice)
		{
			case 1:
			{
				string allfile,encrypted,key;
				printf("Enter key : ");
				cin>>key;
				
	
				printf("Input file : ");
				cin>>inputfile;
				allfile=readfile(inputfile);

				key=filterOut(key);
				allfile=filterOut(allfile);
				
				length_key=key.length();
				length_file=allfile.length();
				
				printf("Output file: ");
				cin>>outputfile;
				
				
				for(i=0;i<allfile.length();i++)
				{
				    encrypted.push_back(((allfile[i]-'a')+(key[i%length_key]-'a'))%26 + 'a');
				}
				
			
				writefile(encrypted,outputfile);
				
			}
				break;
			case 2:
			{
				string allfile,key,plain;
				printf("Enter key : ");
				cin>>key;
				
	
				printf("Input file : ");
				cin>>inputfile;
				allfile=readfile(inputfile);

				filterOut(key);
				filterOut(allfile);
				
				length_key=key.length();
				length_file=allfile.length();
				
				printf("Output file: ");
				cin>>outputfile;
				
				for(i=0;i<allfile.length();i++)
				{
				    plain.push_back(((allfile[i]-'a')-(key[i%length_key]-'a') + 26)%26 + 'a');
				}
				
			    
				writefile(plain,outputfile);
		    }
				break;
			
		
			case 3:

				return 0;
			default:
				printf("Invalid choice.");
		}
		
	}
	
	return 0;
}
