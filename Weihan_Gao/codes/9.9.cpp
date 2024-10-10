#include <algorithm>
#include <iostream>
#include <random>
#include <numeric>
using namespace std;


string MonoalphabeticSubstitutionEncrypt(string plainText) {
	//srand(1);
	//std::random_device rd;
	std::mt19937 g(1);

	string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	string cypherText = plainText;
	shuffle(alphabet.begin(), alphabet.end(), g);


	for (int i = 0; i < plainText.length(); i++) {
		cypherText[i] = alphabet[(plainText[i] - 'A')];
		//cout << alphabet[(plainText[i] - 'A')] << endl;
	}
	return cypherText;
}


int main() {
	string cypherText;
	cypherText = MonoalphabeticSubstitutionEncrypt("THECOOKIESAREINTHEFRIDGE");
	cout << cypherText << endl;
}