#include<bits/stdc++.h>
using namespace std;

long long fastPow(long long base,long long p,long long MOD)
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
long long gcd(long long a,long long b)
{
    if(a==0)
        return b;
    return gcd(b%a,a);
}
long long getMMI(long long num,long long mod)
{
	int i=0;
	for(i=1;i<mod;i++)
	{
		if((i*num)%mod==1)
			return i;
	}
	return -1;
}
long long modmulinverse(long long a,long long m)
{
    long long x = 0,y = 1,u = 1,v = 0;
    long long e = m,f = a;
    long long c,d,q,r;
    while(f != 1)
    {
        q = e/f;
        r = e%f;
        c = x-q*u;
        d = y-q*v;
        x = u;
        y = v;
        u = c;
        v = d;
        e = f;
        f = r;
    }
    u = (u+m)%m;
    return u;
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
vector<long long> readfile_v(char *filename)
{
	vector<long long> nums;
	long long temp;
	ifstream input;
	input.open(filename,ios::in);
	
	while(input>>temp)
	{
	    nums.push_back(temp);
	}
	input.close();
	return nums;
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
void writefile_v(vector<long long> nums,char *filename)
{
	ofstream output;
	output.open(filename,ios::out);
	for(int i=0;i<nums.size();i++)
	    output<<nums[i]<<" ";
	output.close();	
	return;
}
int main(int argc,char *argv[])
{	
	
	
	char outputfile[101],inputfile[101],keyfile[101];
	int length_file,length_encrypted,length_key;

	while(1)
	{
		
		
		printf("---------------------------------------\nMENU:\n1. Encrypt a file\n2. Decrypt a file\n3. Generate a pair\n4. Exit\nEnter your choice: ");
		int choice,i,k,j,key_dim,blocksize;
		long long d,e,n,prime1,prime2,phiofn;
		string allfile,encrypted,plain;
	    vector<long long> allfile_v,encrypted_v;
	
		cin>>choice;
		switch(choice)
		{
			case 1:
			{
				
				
	
				printf("Input file : ");
				cin>>inputfile;
				printf("Output file : ");
				cin>>outputfile;
				allfile=readfile(inputfile);
				allfile=filterOut(allfile);
				
				length_file=allfile.length();
				
				cout<<"Enter encryption key pair (e,n) ";
				cin>>e>>n;
		        bsagain1:
		        cout<<"Enter blocksize : ";
		        cin>>blocksize;
		        if(fastPow(26,blocksize,1000000000000000ll)>=n)
		        {
		            cout<<"Block size too large"<<endl;
		            goto bsagain1;
		        }
				
				while(allfile.length()%blocksize!=0)
				    allfile.push_back('x');
				
				for(i=0;i<allfile.length();i+=blocksize)
				{
				    long long thisone=0;
				    for(j=0;j<blocksize;j++)
				    {
				         thisone*=26;
				        thisone+=((allfile[i+j]-'a'));
				       
				        thisone%=n;
				       
				    }
				  //  cout<<thisone<<" "<<fastPow(thisone,e,n)<<endl;
				    encrypted_v.push_back(fastPow(thisone,e,n));
				}
				
				writefile_v(encrypted_v,outputfile);
			
			}
				break;
			case 2:
			{
					
				
	
				printf("Input file : ");
				cin>>inputfile;
				allfile_v=readfile_v(inputfile);
			
				length_file=allfile.length();
				printf("Output file: ");
				cin>>outputfile;
				 
			    cout<<"Enter decryption key  pair ";
		        cin>>d>>n;
		        bsagain2:
		        cout<<"Enter blocksize : ";
		        cin>>blocksize;
		        if(fastPow(26,blocksize,1000000000000000ll)>=n)
		        {
		            cout<<"Block size too large"<<endl;
		            goto bsagain2;
		        }
				
				for(i=0;i<allfile_v.size();i++)
                {
                   
                    long long num=fastPow(allfile_v[i],d,n);
                    string temp;
                    for(j=0;j<blocksize;j++)
                    {
                        char ch=(num%26)+'a';
                        num/=26;
                        temp.push_back(ch);
                        cout<<"pushing "<<ch;
                    }
                    cout<<"temp is "<<temp<<endl;
                    reverse(temp.begin(),temp.end());
                           cout<<"temp is "<<temp<<endl;
                    plain.append(temp);
                }
				
				
				writefile(plain,outputfile);
			
		    }
				break;
			
		    case 3:
		        cout<<"Enter two prime numbers :";
				cin>>prime1>>prime2;
				n=prime1*prime2;
				phiofn=(prime1-1)*(prime2-1);
				do
				{
				    e=rand()%(phiofn-1) +1;
				}while(gcd(e,phiofn)!=1);
					d=modmulinverse(e,phiofn);
				cout<<"public key ("<<e<<","<<n<<")"<<endl;
				cout<<"private key ("<<d<<","<<n<<")"<<endl;
				break;
			case 4:

				return 0;
			default:
				printf("Invalid choice.");
		}
		
	}
	
	return 0;
}
