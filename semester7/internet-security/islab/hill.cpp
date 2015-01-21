#include<bits/stdc++.h>
using namespace std;
#define MOD 26
long long fastPow(long long base,long long p)
{
	long long ans=1;
	while(p)
	{
		if(p%2==1)
		{
			ans=(ans*base)%MOD;
			
		}
		base=(base*base)%MOD;
		p>>=1;
	}
	return ans;
}

long long getMMI(long long num)
{
	int i=0;
	for(i=1;i<MOD;i++)
	{
		if((i*num)%MOD==1)
			return i;
	}
	return -1;
}
int** delFromMat(int **mat,int n,int skiprow,int skipcol)
{
	int **b=new int*[n-1];
	
	int i,j,i2,j2;
	for(i=0;i<n-1;i++)
		b[i]=new int[n-1];
	for(i=0,i2=0;i<n;i++)
	{
		if(i==skiprow)
			continue;
		for(j=0,j2=0;j<n;j++)
		{		
			if(j==skipcol)	
				continue;
			b[i2][j2]=mat[i][j];
			j2++;	
		}	
		i2++;
	}
	return b;
}
void printmat(int **a,int n)
{
	cout<<"---"<<endl;
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
	cout<<"---"<<endl;
}
int findDet(int **a,int n)
{
	if(n==1)
		return a[0][0]%MOD;
	int det=0;
	for(int i=0;i<n;i++)
	{
		int **temp=delFromMat(a,n,0,i);
		int tdet=findDet(temp,n-1);
		
		if(i%2==0)
			det+=(tdet*a[0][i]);
		else
			det-=(tdet*a[0][i]);
		free(temp);
	}
	while(det<0)
		det+=MOD;
	det%=MOD;
	
	cout << det;

	return det;
}
void getTranspose(int **a,int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			int temp=a[i][j];
			a[i][j]=a[j][i];
			a[j][i]=temp;
		}
	}
}
void multiplyBy(int **mat,int n,int mby)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			mat[i][j]=(mat[i][j]*mby);
			while(mat[i][j]<MOD)
				mat[i][j]+=MOD;
			mat[i][j]%=MOD;
		}
		
	
	}
}
int ** findInv(int **a,int n)
{
	int det=findDet(a,n);
	
	if(det==0)
		return NULL;
	int **b=new int*[n];
	int i,j;
	for(i=0;i<n;i++)
		b[i]=new int[n];
	for(i=0;i<n;i++)
	{	
		for(j=0;j<n;j++)
		{
			int **t=delFromMat(a,n,i,j);
			b[i][j]=findDet(t,n-1);
			if((i+j)%2==1)
				b[i][j]*=-1;
			free(t);
		}
	}
	getTranspose(b,n);
	multiplyBy(b,n,getMMI(det));
	return b;
}
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
		if(isalpha(str[i]))
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
	/*int n;
	cin>>n;
	int i,j;
	int **mat;
	mat=new int*[n];
	for(i=0;i<n;i++)
	{
		mat[i]=new int[n];
		for(j=0;j<n;j++)
			cin>>mat[i][j];
	}
	int **inv=findInv(mat,n);
	for(i=0;i<n;i++)
	{	
		for(j=0;j<n;j++)
			cout<<inv[i][j]<<" ";
		cout<<endl;
	}*/
	
	char outputfile[101],inputfile[101],keyfile[101];
	int length_file,length_encrypted,length_key;

	while(1)
	{
		
		
		printf("---------------------------------------\nMENU:\n1. Encrypt a file\n2. Decrypt a file\n3. Exit\nEnter your choice: ");
		int choice,i,k,j,key_dim;
		int **key_mat, **inv_keymat;
		cin>>choice;
		switch(choice)
		{
			case 1:
			{
				string allfile,encrypted,key;
				
				
	
				printf("Input file : ");
				cin>>inputfile;
				printf("Output file : ");
				cin>>outputfile;
				allfile=readfile(inputfile);
				allfile=filterOut(allfile);
				
				length_file=allfile.length();
				
				printf("Enter dimensions of key matrix : ");
				cin>>key_dim;
				key_mat=new int*[key_dim];
				for(i=0;i<key_dim;i++)
				        key_mat[i]=new int[key_dim];
				printf("Enter the matrix\n");
				for(i=0;i<key_dim;i++)
					for(j=0;j<key_dim;j++)
					        cin>>key_mat[i][j];
		            
		                while(allfile.length()%key_dim !=0)
		                        allfile.push_back('x');
		                    cout<<"all file is "<<allfile<<endl;
		                cout<<"determinant is "<<findDet(key_mat,key_dim)<<endl;
		                for(i=0;i<allfile.length();i+=key_dim)
		                {
		                        
		                        for(j=0;j<key_dim;j++)
		                        {
		                                int thisone=0;
		                                for(k=0;k<key_dim;k++)
        		                                thisone+=((allfile[i+k]-'a')*(key_mat[j][k]));
        		                        thisone%=MOD;
        		                        encrypted.push_back(thisone+'a');
		                        }
		                }
				
				writefile(encrypted,outputfile);
				free(key_mat);
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
				printf("Output file: ");
				cin>>outputfile;
				 
				printf("Enter dimensions of key matrix : ");
				cin>>key_dim;
				key_mat=new int*[key_dim];
				for(i=0;i<key_dim;i++)
				        key_mat[i]=new int[key_dim];
				printf("Enter the matrix\n");
				for(i=0;i<key_dim;i++)
					for(j=0;j<key_dim;j++)
					        cin>>key_mat[i][j];
			        inv_keymat=findInv(key_mat,key_dim);
			        free(key_mat);
			        key_mat=inv_keymat;
                                cout<<"inverse is "<<endl;
                                for(i=0;i<key_dim;i++)
                                {
                                        for(j=0;j<key_dim;j++)
                                                cout<<key_mat[i][j]<<" ";
                                        cout<<endl;
                                }
			        while(allfile.length()%key_dim !=0)
		                        allfile.push_back('x');
		                for(i=0;i<allfile.length();i+=key_dim)
		                {
		                        
		                        for(j=0;j<key_dim;j++)
		                        {
		                                int thisone=0;
		                                for(k=0;k<key_dim;k++)
        		                                thisone+=((allfile[i+k]-'a')*(key_mat[j][k]));
        		                        thisone%=MOD;
        		                        plain.push_back(thisone+'a');
		                        }
		                }     
					        
				
				
				
				writefile(plain,outputfile);
				free(key_mat);
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
