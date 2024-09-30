#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

vector<string> LoadAllTokens(string filename);
void Biasedsort(vector<string>&);
bool mySort(string a, string b);

int main() {
	string filename = "MeFirst.txt";
	vector<string> allTokens;
	allTokens = LoadAllTokens(filename);


	Biasedsort(allTokens);

	for (vector<string>::iterator itr = allTokens.begin(); itr != allTokens.end(); ++itr) {
		cout << *itr << endl;
	}


	return 0;
}


void Biasedsort(vector<string>& myString) {
	sort(myString.begin(),
		myString.end(),
		mySort);

}
bool mySort(string a, string b) {
	if (a == "MeFirst" || b == "")
		return a.length() < b.length();
	else
		return lexicographical_compare(
			a.begin(),
			a.end(),
			b.begin(),
			b.end());
}


vector<string> LoadAllTokens(string filename) {
	vector<string> allTokens;
	ifstream input(filename.c_str());
	if (!input.is_open())
		cerr << "Couldn't open the file" << endl;

	istream_iterator<string> itr(input);
	istream_iterator<string> eos;

	while (true) {
		if (itr == eos)
			break;
		allTokens.push_back(*itr);
		itr++;
	}

	return allTokens;
}
