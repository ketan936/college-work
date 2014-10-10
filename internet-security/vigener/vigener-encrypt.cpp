#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

int main(){
	ifstream i1,i2;
	ofstream o1;
	char ch;
	i1.open("input.txt");
	i2.open("key.txt");
	o1.open("output.txt");
	string input="",key="";
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
	if((ch>='a' && ch<='z') ){input.push_back(ch);}
   	 }
	}
	cin.clear();
	int i;
	for(i=0;i<input.length();i++){
	int temp = input.at(i)+key.at(i%key.length())-97-97;
	temp=temp%26;
//	cout<<input.at(i)<<" + "<<key.at(i%key.length())<<" = "<<temp<<" ";
	cout<<(char)(temp+97);
	o1<<(char)(temp+97);
	}
	cout<<endl;
	i1.close();
	o1.close();
	i2.close();
}
