#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <utility>
#include <fstream>
using namespace std;
char data[1000];
char key[1000];
char cipher[1000];
char decipher[1000];
int var_int_case, var_int_loop_i;
char var_char_array[10000], var_char_array_encrypted[10000], *pointer_char;
ifstream var_read;
ofstream var_write;
char var_char_read;
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

int writedata(char *ptr) // read data from file
		{
	var_write.open("output.txt");

	var_write << ptr;

	var_write.close();
	return 1;
}
void encrypt() {
	int i;
	printf("Enter Message: ");
	readdata();
	printf("%s\n",var_char_array);
	printf("Enter Key: ");
	encrypt_function: scanf(" %[^\n]", key);  //key len cannot be 1
	int key_length = strlen(key);
	if (key_length <= 1) {
		printf("Key Length should be > 1. Enter Key again: ");
		goto encrypt_function;
	}
	vector<pair<char, int> > mykey;
	for (i = 0; i < key_length; i++) {
		mykey.push_back(make_pair(key[i], i));
	}

	sort(mykey.begin(), mykey.end());

	for (i = 0; i < mykey.size(); i++) {
		printf(" %c %d\n", mykey[i].first, mykey[i].second);
	}

	i = 0;
	int j = 0;
	for (i = 0; var_char_array[i] != '\0'; i++) {
		if (var_char_array[i] == ' ') {
			continue;
		} else if (var_char_array[i] >= 'A' && var_char_array[i] <= 'Z') {
			data[j] = var_char_array[i] + 32;
			j++;
		} else {
			data[j] = var_char_array[i];
			j++;
		}
	}
	data[j] = '\0';
	int data_length = strlen(data);
	printf("%s\n", data);

	int upto = data_length % key_length;
	if (upto != 0) {
		upto = key_length - upto;
	}
	i = data_length;
	for (j = 0; j < upto; j++) {
		data[i] = 'x';
		i++;
	}
	data[i] = '\0';
	data_length = strlen(data);
	printf("%s\n", data);
	int z = 0;
	for (i = 0; i < mykey.size(); i++) {
		j = mykey[i].second;
		for (int k = j; k < data_length; k += key_length) {
			cipher[z] = data[k];
			z++;
		}
	}
	cipher[z] = '\0';
	printf("%s\n", cipher);
	writedata(cipher);
}

void decrypt() {
	int i, j;
	printf("Enter Key to Decrypt: ");
	decrypt_function: scanf(" %[^\n]", key);  //key len cannot be 1
	int key_length = strlen(key);
	if (key_length <= 1) {
		printf("Key Length should be > 1. Enter Key again: ");
		goto decrypt_function;
	}
	vector<pair<char, int> > mykey;
	for (i = 0; i < key_length; i++) {
		mykey.push_back(make_pair(key[i], i));
	}
	sort(mykey.begin(), mykey.end());
	int z = 0;
	int data_length = strlen(cipher);
	for (i = 0; i < mykey.size(); i++) {
		j = mykey[i].second;
		for (int k = j; k < data_length; k += key_length) {
			decipher[k] = cipher[z];
			z++;
		}
	}
	decipher[z] = '\0';
	printf("%s\n", decipher);
	int plen = strlen(decipher);
	plen--;
	while (decipher[plen] == 'x') {
		plen--;
	}
	plen++;
	decipher[plen] = '\0';
	printf("%s\n", decipher);
}

int main() {
	while (1) {
		int choice;
		printf("[0] Encrypt\n[1] Decrypt\n");
		printf("Enter Choice: ");
		scanf(" %d", &choice);
		switch (choice) {
		case 0:
			encrypt();
			break;
		case 1:
			decrypt();
			break;
		case 3:
			return 0;
			break;
		}
	}
	return 0;
}
