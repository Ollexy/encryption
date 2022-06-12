#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;

string generateKey(string wordToEncrypt, string keyWord);
string encryption(string wordToEncrypt, string keyWord);
string decryption(string cipherWord, string keyWord);
void solve();

int main()
{
	solve();
	
	return 0;
}

/* Setting keyWord length to wordtoEncryption length*/
string generateKey(string wordToEncrypt, string keyWord)
{
	int x = wordToEncrypt.size();

	for (int i = 0; ; i++)
	{
		if (x == i)
			i = 0;
		if (keyWord.size() == wordToEncrypt.size())
			break;
		keyWord.push_back(keyWord[i]);
	}
	return keyWord;
}

//Encrypting wordToEncrypt
string encryption(string wordToEncrypt, string keyWord)
{
	string cipherWord;

	for (int i = 0; i < wordToEncrypt.size(); i++)
	{
		// converting in range 0-25
		char x = (wordToEncrypt[i] + keyWord[i]) % 26;

		// convert into alphabets(ASCII)
		x += 'A';

		cipherWord.push_back(x);
	}
	return cipherWord;
}

//Decrypting cipherWord
string decryption(string cipherWord, string keyWord)
{
	string orig_text;

	for (int i = 0; i < cipherWord.size(); i++)
	{
		// converting in range 0-25
		char x = (cipherWord[i] - keyWord[i] + 26) % 26;

		// convert into alphabets(ASCII)
		x += 'A';
		orig_text.push_back(x);
	}
	return orig_text;
}

void solve() {
	string str;
	string keyWord;

	cout << "Enter word you want to encrypt: ";
	cin >> str;
	cout << "Enter key word: ";
	cin >> keyWord;

	string key = generateKey(str, keyWord);
	string cipher_text = encryption(str, key);

	cout << "Ciphertext : "
		<< cipher_text << "\n";

	cout << "Original/Decrypted Text : "
		<< decryption(cipher_text, key);
}
