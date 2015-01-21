#include<bits/stdc++.h>
using namespace std;
int bitmasks[8]={128,64,32,16,8,4,2,1};
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
	srand(time(NULL));
	char outputfile[101],inputfile[101],keyfile[101];
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
				
				
	
				printf("Input file : ");
				cin>>inputfile;
				allfile=readfile(inputfile);

				
				allfile=filterOut(allfile);
				
				
				length_file=allfile.length();
				
				printf("Enter length of key to be generated : ");
				cin>>length_key;
				for(i=0;i<length_key;i++)
					key.push_back(rand()%2 +'0');
				printf("Output file: ");
				cin>>outputfile;
				
				
				for(i=0;i<allfile.length();i++)
				{
					cout<<allfile[i]<<endl;
					
				
					for(int j=0;j<8;j++)
					{
						cout<<(((allfile[i]&bitmasks[j])==0)?0:1)<<" xor "<<(int)(key[(i*8+j)%length_key]-'0') <<"="<<(char)((  (((allfile[i]&bitmasks[j])==0)?0:1)  + ( key[(i*8+j)%length_key]-'0' ) )%2 + '0') <<endl;
					    encrypted.push_back( (  (((allfile[i]&bitmasks[j])==0)?0:1)  + ( key[(i*8+j)%length_key]-'0' ) )%2 + '0');
						
					}
					cout<<endl<<endl;
				}
				
				writefile(key,"key");
				writefile(encrypted,outputfile);
				
			}
				break;
			case 2:
			{
				string allfile,plain,key;
				
				
	
				printf("Input file : ");
				cin>>inputfile;
				allfile=readfile(inputfile);
				allfile=filterOut(allfile);
				length_file=allfile.length();
				
				printf("Key file : ");
				cin>>keyfile;
				key=readfile(keyfile);
				length_key=key.length();
				printf("Output file: ");
				cin>>outputfile;
				 
				
				for(i=0;i<length_file;i+=8)
				{
					char ch=0;
					
					for(int j=0;j<8 && i+j<length_file;j++)
					{
					    ch=(ch<<1) +( ( ( allfile[i+j]-'0') + ( key[(i+j)%length_key]-'0' ) )%2 );
						//cout<<i<<":"<<j<<endl;
					}
					plain.push_back((char)ch);
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
