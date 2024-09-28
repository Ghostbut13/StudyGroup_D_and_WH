#include <iostream>
#include <sstream>
using namespace std;

bool HasHexLetter();


int main() {
	bool a = HasHexLetter();
	if (a)
		cout << "no ABCDEF" << endl;
	else
		cout << "has ABCDEF" << endl;
	return 0;
}


bool HasHexLetter() {
	stringstream HexInteger;
	int input;
	int Result;
	cin >> dec >> input;
	//cout << hex << input << endl;
	HexInteger << hex << input;
	HexInteger >> dec >> Result;
	//cout << Result << endl;
	if (Result == input)
		return 1;
	else
		return 0;
}