#include <iostream>
#include <fstream>
using namespace std;
int main(){
	string cipher="",key="";
	char ch;
	ifstream i1,i2;
	ofstream o1;
	i1.open("output.txt");
	i2.open("key.txt");
	o1.open("decipher.txt");  
	string input="",decipher="";
	while(!i1.eof())
	{
    	i1>>ch;
    	if(!i1.eof())
   	 {
	cipher.push_back(ch);
   	 }
	}
	cin.clear();
	while(!i2.eof())
	{
    	i2>>ch;
    	if(!i2.eof())
   	 {
	key.push_back(ch);
   	 }
	}
	cin.clear();
	int i;
	for(i=0;i<cipher.length();i++){
	cout<<(char)((cipher.at(i)-48)^(key.at(i%key.length())-48)+48);
	decipher.push_back((char)((cipher.at(i)-48)^(key.at(i%key.length())-48)+48));
	}
	cout<<endl;
	for(i=0;i<cipher.length();i)
	{
	cout<<(char)
	((((decipher.at(i)-48)*128)+
	((decipher.at(i+1)-48)*64)+
	((decipher.at(i+2)-48)*32)+
	((decipher.at(i+3)-48)*16)+
    ((decipher.at(i+4)-48)*8)+
    ((decipher.at(i+5)-48)*4)+
    ((decipher.at(i+6)-48)*2)+
    ((decipher.at(i+7)-48)*1)));
	o1<<(char)
	((((decipher.at(i)-48)*128)+
	((decipher.at(i+1)-48)*64)+
	((decipher.at(i+2)-48)*32)+
	((decipher.at(i+3)-48)*16)+
     ((decipher.at(i+4)-48)*8)+
	 ((decipher.at(i+5)-48)*4)+
	 ((decipher.at(i+6)-48)*2)+
	 (((decipher.at(i+7)-48)*1))));
	i=i+8;
	}
	o1<<endl;
	i1.close();
	i2.close();
	o1.close();
	return 0;
}
