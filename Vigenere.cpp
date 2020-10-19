#include "bits/stdc++.h"
using namespace std;

string encrypt(string input, string key) {
	for(int i = 0, j = 0; i < input.length(); i++, j++) {
		if(j >= key.length()) {
			input[i] = 'A' + (input[i] + key[0]) % 26;
			j = 0;
		} else {
			input[i] = 'A' + (input[i] + key[j]) % 26;
		}
	}
	return input;
}
 
string decrypt(string input, string key) {
	for(int i = 0, j = 0; i < input.length(); i++, j++) {
		if(j >= key.length()) {
			input[i] = 'A' + (input[i] - key[0] + 26) % 26;
			j = 0;
		} else {
			input[i] = 'A' + (input[i] - key[j] + 26) % 26;
		}
	}
	return input;
}
// similar approach towards the vigenere cipher 
string cipherText(string str, string key)
{
	string cipher_text;
	int keylen=key.length();
	for (int i = 0; i < str.size(); i++)
	{
		char x = (str[i] + key[i%keylen]) %26;
		x += 'A';
		cipher_text.push_back(x);
	}
	return cipher_text;
}
string originalText(string cipher_text, string key)
	{
	string orig_text;
	int keylen=key.length();
	for (int i = 0 ; i < cipher_text.size(); i++)
	{
		char x = (cipher_text[i] - key[i%keylen] + 26) %26;
		x += 'A';
		orig_text.push_back(x);
	}
	return orig_text;
}

int main() {
	cout<<"######## Vigenere Cipher ########\n";
	string input;
	string key;
	string output;
	bool mode;
	int modeInput = 1;
	
	cout<<"\nEnter the string to be encrypted or decrypted: ";
	cin>>input;
	cout<<"\nEnter the Key: ";
	cin>>key;
	cout<<"\nEnter the Mode (1 for encryption & o for decryption): ";
	cin>>modeInput;
	// convert the given input and the key to upper case if it is in lowercase
	transform(input.begin(),input.end(),input.begin(),::toupper);
	
	transform(key.begin(),key.end(),key.begin(),::toupper);
	
	if(modeInput == 1) {
		output = encrypt(input, key);
		cout<<"\nEncrypted string is: "<<output<<"\n";	
	}
	else {
		output = decrypt(input, key);
		cout<<"\nDecrypted string is: "<<output<<"\n";	
	}
	return 0;
}
