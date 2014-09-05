#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int var_int_case,var_int_loop_i;
char var_char_array[10000],var_char_array_encrypted[10000],*pointer_char;
ifstream var_read;
char var_char_read;

int readdata() // read data from file
{
	var_read.open("input.txt");
	var_int_loop_i=0;
	if(var_read.eof())
	{
	return 0;
	}
	while(!var_read.eof())
	{
	var_read>>var_char_read;
	if(var_char_read>='A' && var_char_read<='Z')
	{
	var_char_read+=32;
	}
	if(var_char_read>='a' && var_char_read<='z')
	{
	var_char_array[var_int_loop_i]=var_char_read;
	var_int_loop_i++;
	}
	}
	var_char_array[var_int_loop_i-1]='\0';
	var_read.close();
	return var_int_loop_i;
}

int encrypt(char *ptr,int key) // Encrypt data with key which is passed as argument
{
	int var_int_temp,var_temp_length=strlen(var_char_array);
	for(var_int_temp=0;var_int_temp<var_temp_length;var_int_temp++)
	{
	if(var_char_array[var_int_temp]+key>'z')
	{
	*ptr=var_char_array[var_int_temp]-26+key;
	}
	else
	{
	*ptr=var_char_array[var_int_temp]+key;
	}
	ptr++;
	}
	*ptr='\0';
	return 0;
}

int decrypt(char *ptr,int key)  // Decrypt data with key which is passed as argument and ask for user to verify it
{
	char *char_pointer_temp=ptr,var_char_temp;
	int var_int_temp,var_temp_length=strlen(ptr);
	for(var_int_temp=0;var_int_temp<var_temp_length;var_int_temp++)
	{
	if(var_char_array_encrypted[var_int_temp]-key<'a')
	{
	cout<<(char)(var_char_array_encrypted[var_int_temp]+26-key);
	}
	else
	{
	cout<<(char)(var_char_array_encrypted[var_int_temp]-key);
	}
	}
	cout<<endl;
	getchar();
	cout<<"Is It Meaningful ? (y/n) : \n\n";
	cin>>var_char_temp;
	if(var_char_temp=='y' || var_char_temp=='Y')
	{
	cout<<"Cipher Is Decrypted "<<endl;
	cout<<"Decryption Key (Particular Solution) = "<<key<<endl;
	return 1;
	}
	return 0;
}

void occurence(int *p,char *c)  // Calculate occurence to use frequency method of decryption
{
	while(*c!='\0')
	{
	*(p+*c-97)=*(p+*c-97)+1;
	c++;
	}

	// Debugging

	/*cout<<endl;
	for(int i=0;i<26;i++)
	{
	cout<<*(p+i)<<" "<<char(i+97)<<endl;;
	}
	cout<<endl;*/

	return ;
}

int maximum(int *p) // find index of maximum number from array and make it zero
{
	int var_int_temp_i,var_int_temp_index=0,var_int_temp_value=0;
	for(var_int_temp_i=0;var_int_temp_i<26;var_int_temp_i++)
	{
		if(*(p+var_int_temp_i)>var_int_temp_value)
		{
			var_int_temp_index=var_int_temp_i;
			var_int_temp_value=*(p+var_int_temp_i);
		}
	}
	*(p+var_int_temp_index)=0;
	return var_int_temp_index-97;
}

int main()
{
	int var_int_local_i,var_int_local_key;
	while(true)
	{
	cout<<"\n1.Encrypt. \n2.Decrypt.\n3.Frequency Method For Decryption.\n4.Exit.\n"<<endl;
	cin>>var_int_case;
	if(readdata()==0)
	{
		cout<<"No Data To Read\nExiting ... \n";
		return -1;
	}
	switch(var_int_case)
	{
	case 1:
	{
	cout<<"Enter Encryption Key : ";
	cin>>var_int_local_key;
	var_int_local_key%=26;
	pointer_char=var_char_array_encrypted;
	if(encrypt(var_char_array_encrypted,var_int_local_key)==0)
	{
	cout<<"Encrypted : "<<endl;
	cout<<var_char_array_encrypted<<endl;
	}
	break;
	}
	case 2:
	{
	for(var_int_local_i=0;var_int_local_i<26;var_int_local_i++)
	{
	if(decrypt(var_char_array_encrypted,var_int_local_i)==1)
	{
	break;
	}
	}
	break;
	}
	case 3:
	{
	int int_array_original[26]={0},int_array_encrypted[26]={0};
	occurence(int_array_original,var_char_array);
	occurence(int_array_encrypted,var_char_array_encrypted);
	for(var_int_local_i=0;var_int_local_i<26;var_int_local_i++)
	{
		if(decrypt(var_char_array_encrypted,abs(maximum(int_array_original)-maximum(int_array_encrypted)))==1)
		{
		break;
		}
	}
	break;
	}
	case 4:
	{
	return 0;
	break;
	}
	default:
	{
		cout<<"Please Follow The Instructions !!"<<endl;
		break;
	}
	}
	}
	system("pause");
	return 0;
}
