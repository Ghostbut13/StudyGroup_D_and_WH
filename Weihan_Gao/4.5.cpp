#include <iostream>
#include <deque>
using namespace std;

string VigenereEncrypt(deque<int> keys, string plaintext);
string VigenereDecrypt(deque<int> keys, string cypertext);

int main() {
	string plaintext = "THECOOKIESAREINFRIDGE";
	deque<int> keys(3);
	keys[0] = 1;
	keys[1] = 3;
	keys[2] = 7;
	string cypertext = VigenereEncrypt(keys, plaintext);
	cout << cypertext << endl;
	keys[0] = 1;
	keys[1] = 3;
	keys[2] = 7;
	plaintext = VigenereDecrypt(keys, cypertext);
	cout << plaintext << endl;
	return 0;
}

string VigenereEncrypt(deque<int> keys, string plaintext)
{
	for (int i = 0; i < plaintext.length(); ++i) {
		int first = keys.front();
		plaintext[i] = plaintext[i] + static_cast<char>(first);
		keys.pop_front();
		keys.push_back(first);
	}

	return plaintext;
}

string VigenereDecrypt(deque<int> keys, string cypertext)
{
	for (int i = 0; i < cypertext.length(); ++i) {
		int first = keys.front();
		cypertext[i] = cypertext[i] - static_cast<char>(first);
		keys.pop_front();
		keys.push_back(first);
	}

	return cypertext;
}
