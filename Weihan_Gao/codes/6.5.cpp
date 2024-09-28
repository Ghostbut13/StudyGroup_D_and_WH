#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<string> LoadAllTokens(string filename);

int main() {
	string filename = "stringTokens.txt";
	vector<string> allTokens;
	allTokens = LoadAllTokens(filename);
	for (vector<string>::iterator itr = allTokens.begin(); itr != allTokens.end(); ++itr) {
		cout << *itr << endl;
	}
	return 0;
}

vector<string> LoadAllTokens(string filename) {
	vector<string> allTokens;
	ifstream input(filename.c_str());
	if (!input.is_open())
		cerr << "Couldn't open the file" << endl;
	
	istream_iterator<string> itr(input);
	istream_iterator<string> eos;

	while(true){
		if (itr == eos)
			break;
		allTokens.push_back(*itr);
		itr++;
	}

	return allTokens;
}
