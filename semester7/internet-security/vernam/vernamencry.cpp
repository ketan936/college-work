#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>    
#include <algorithm>
#include <string.h>
using namespace std;
string convrt(char c) {
	cout << "char" << c << endl;
	int i;
	string s = "";
	for (i = 0; i < 255; i++) {
		if ((char) (i) == c) {
			break;
		}
	}
	cout << i;
	int j = 2, k = i;
	for (i = 0; i < 8; i++) {
		s = (char) ((k % j) + 48) + s;
		k = k / 2;
		//cout<<"char"<<c<<endl;
	}

	return s;
}

char* itoa(int value, char* result, int base) {

	// check that the base if valid

	if (base < 2 || base > 16) {
		*result = 0;
		return result;
	}

	char* out = result;

	int quotient = value;

	do {

		*out = "0123456789abcdef"[std::abs(quotient % base)];

		++out;

		quotient /= base;

	} while (quotient);

	// Only apply negative sign for base 10

	if (value < 0 && base == 10)
		*out++ = '-';

	reverse(result, out);

	*out = 0;

	return result;

}
int main() {

	ifstream i1, i2;
	ofstream o1, o2;
	char ch;
	i1.open("input.txt");
	o2.open("key.txt");
	o1.open("output.txt");
	string input = "", key = "", random = "";
	int ran, bit;
	srand (time(NULL));ran
	= rand() % 10;
	//cout<<"Random : "<<ran<<endl;
	cout << "enter bit (multiple of 8) ";
	cin >> bit;
	char arr[10];

	while (bit > 0) {
//	srand(time(NULL));
		ran = rand() % 10;
		cout << ran << endl;
		random = itoa(ran, arr, 10) + random;
		bit = bit - 8;
	}
	cout << endl;
	cout << random << endl;
	stringstream ss(random);
	int i;
	if ((ss >> i).fail()) {
		cout << "error";
	}

	cout << i << endl;
	ran = i;
	while (ran > 0) {
		key = convrt((ran % 10)) + key;

		ran = ran / 10;
	}
	o2 << key;
	cout << key << "  keyhello" << endl;
	while (!i1.eof()) {
		i1 >> ch;
		if (!i1.eof()) {
			input = input + convrt(ch);
		}
	}
	cout << "input" << endl;
	cout << input;
	cout << "output" << endl;
	for (i = 0; i < input.length(); i++) {
		cout << ((input.at(i) - 48) ^ (key.at(i % key.length()) - 48));
		o1 << ((input.at(i) - 48) ^ (key.at(i % key.length()) - 48));
	}
}
