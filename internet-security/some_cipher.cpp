#include <iostream>
#include <stack>
#include <string>
using namespace std;

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
	cin >> cipher;
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
	for (int i = 3; i == 3; i++) {
		cout << "Checking for level: " << i << endl;
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

}

