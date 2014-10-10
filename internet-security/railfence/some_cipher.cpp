#include <iostream>
#include <stack>
#include <string>
#include <fstream>
using namespace std;
char var_char_array[10000], var_char_array_encrypted[10000], *pointer_char;
ifstream var_read;
ofstream var_write;
char var_char_read;
int var_int_case, var_int_loop_i;

stack<int> create_stack(int level) {
	stack<int> my_stack;
	for (int i = 1; i < level; ++i) {
		my_stack.push(i);
	}
	for (int i = level - 2; i >= 0; --i) {
		my_stack.push(i);
	}
	return my_stack;
}
string reverse(string s) {
	string result = "";
	for (int i = 0; i < s.length(); i++) {
		result = s[i] + result;
	}

	return result;
}
int readdata() // read data from file
{
	var_read.open("input.txt");
	var_int_loop_i = 0;
	if (var_read.eof()) {
		return 0;
	}
	while (!var_read.eof()) {
		var_read >> var_char_read;
		if (var_char_read >= 'A' && var_char_read <= 'Z') {
			var_char_read += 32;
		}
		if (var_char_read >= 'a' && var_char_read <= 'z') {
			var_char_array[var_int_loop_i] = var_char_read;
			var_int_loop_i++;
		}
	}
	var_char_array[var_int_loop_i - 1] = '\0';
	var_read.close();
	return var_int_loop_i;
}

int writedata(string ptr) // read data from file
		{
	var_write.open("output.txt");

	var_write << ptr;

	var_write.close();
	return 1;
}

string add_x(string s , int pos){
	cout << "this is the string before"<<s<<endl;
	for (int i = pos+1; i <= s.length(); ++i) {
		s.insert(i,"x");
		cout<<"hi: "<<s;
		i++;
	}
	cout << "this is the string"<<s<<endl;
	return s;

}
string remove_x(string str, char x) {
	string output;
	for (size_t i = 0; i < str.size(); ++i)
		if (str[i] != x)
			output += str[i];
	return output;
}

int main() {

	string cipher;
	int n;

	cout << "Enter a string: ";
	readdata();
	cipher=var_char_array;
	cout << cipher << endl;

	cout << "Enter a level of cipher: ";
	cin >> n;

	string parts[n];
	stack<int> my_stack;
	for (int i = 0; i < cipher.length(); i++) {
		if (my_stack.empty())
			my_stack = create_stack(n);
		cout << "my stack: " << my_stack.top() << endl;
		for (int j = 0; j < n; j++)
			parts[j] += ' ';
		parts[my_stack.top()][parts[0].length() - 1] = cipher[i];
		my_stack.pop();
	}
	while (!my_stack.empty()) {
		for (int j = 0; j < n; j++)
			parts[j] += ' ';
		parts[my_stack.top()][parts[0].length() - 1] = 'x';
		my_stack.pop();
	}
	for (int j = 0; j < n; j++)
		parts[j] += ' ';
	parts[0][parts[0].length() - 1] = 'x';

	cout << "parts are: " << endl;
	for (int i = 0; i < n; ++i) {
		cout << parts[i] << endl;
	}

	string encrypted;
	for (string s : parts) {
		encrypted += s;
	}
	encrypted = remove_x(encrypted, ' ');
	cout << "encrypted string is: " << encrypted << endl;
	writedata(encrypted);

		cout << "Enter level: " << endl;
		int i;
		cin >> i;
		string other_parts[i];
		int length_of_top = ((encrypted.length()) / (2 * (i - 1))) + 1;
		other_parts[i - 1] = encrypted.substr(
				encrypted.length() - length_of_top + 1, length_of_top - 1);
		other_parts[0] = encrypted.substr(0, length_of_top);
		other_parts[0]= add_x(other_parts[0],1 );
		other_parts[i-1]= add_x(other_parts[i-1],0 );

		int lenght_of_rest = (length_of_top * 2) - 2;
		for (int it = 1; it < i - 1; ++it) {
			other_parts[it] = encrypted.substr(
					length_of_top + (lenght_of_rest * (it - 1)),
					lenght_of_rest);
		}

		cout << "other_parts are: " << endl;
		for (int k = 0; k < i; ++k) {
			cout << other_parts[k] << endl;
		}
		string result;
		for (int it = 0; it < (length_of_top - 1) * 2; ++it) {
			string temp;
			for (int k = 0; k < i; ++k) {
				temp += other_parts[k][it];

			}
			if (it%2!=0)
						temp=reverse(temp);
					result+=temp;
		}
		cout << "deciphered string is: " << remove_x(result, 'x') << endl;


}

