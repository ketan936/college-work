#include <iostream>
#include <cstring>
#include <cmath>
#include <fstream>

using namespace std;

int main(){
ifstream i1,i2;
ofstream o1;
o1.open("decipher.txt");
i1.open("output.txt");
i2.open("key.txt");
char ch;
string cipher="",key="";
while(!i2.eof())
{
    i2>>ch;
    if(!i2.eof())
    {
        if(ch>='A' && ch<='Z')
	{
	ch=ch+32;
	}
	if((ch>='a' && ch<='z') || (ch>='0' && ch<='9'))
	{
	key.push_back(ch);
	}
    }
}
cin.clear();
while(!i1.eof())
{
    i1>>ch;
    if(!i1.eof())
    {
       if(ch>='A' && ch<='Z'){ch=ch+32;}
       if((ch>='a' && ch<='z') ){cipher.push_back(ch);}
    }
}
cin.clear();
int i;
for(i=0;i<cipher.length();i++){
if(key.at(i%key.length())<=cipher.at(i))
{
cout<<(char)(abs(cipher.at(i)-key.at(i%key.length()))+97);
o1<<(char)(abs(cipher.at(i)-key.at(i%key.length()))+97);
}
else
{
cout<<(char)(((26-key.at(i%key.length())+97)+(cipher.at(i)-97))%26+(97));
o1<<(char)(((26-key.at(i%key.length())+97)+(cipher.at(i)-97))%26+(97));
}
}
cout<<endl;
i1.close();
o1.close();
i2.close();
}
