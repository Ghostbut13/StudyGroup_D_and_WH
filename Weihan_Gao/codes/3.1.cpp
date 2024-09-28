#include <iostream>
#include <sstream>
using namespace std;

string ExtractFirstToken();

int main() {
	string a = ExtractFirstToken();
	cout << a << endl;
	return 0;
}

string ExtractFirstToken() {
	string myString, FirstToken;
	getline(cin, myString);
	stringstream myToken;
	myToken << myString;
	myToken >> FirstToken ;
	if (!myToken.fail())
		return FirstToken;
	else
		return "bad";

}