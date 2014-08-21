#include<iostream>
using namespace std;

int main(){

string cipher;
int n;

cout << "Enter a string: ";
cin >> cipher;
cout << cipher <<endl;

cout << "Enter a level of cipher: ";
cin >> n;

string parts[n];

for (int i=0;i < cipher.length();i++){
	int pos=i%n;
	cout << "pos: " << pos <<endl;
	parts[pos] += cipher[i];
	
} 
cout << "parts are: " << endl;
cout << parts[0] <<endl;
cout << parts[1] <<endl;
cout << parts[2] <<endl;
string encrypted;
for (string s : parts){
	encrypted += s;
}
cout << encrypted <<endl;
for (int i=3;i==3;i++){
cout << "Checking for level: " << i << endl;
string other_parts[i];
for (int j=0;j<encrypted.length();j++){
	other_parts[j%i]+=encrypted[j];
}

cout << "other_parts are: " << endl;
cout << other_parts[0] <<endl;
cout << other_parts[1] <<endl;
cout << other_parts[2] <<endl;

}


}
