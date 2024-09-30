#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

vector<int> LoadAllTokens(string filename);
void PrintVector(vector<int> myVector);


int main() {
	string filename = "int.txt";
	vector<int> allints;
	allints = LoadAllTokens(filename);

	PrintVector(allints);
	return 0;
}



void PrintVector(vector<int> myVector) {
	ostream_iterator<int> itr(cout, " ");
	copy(myVector.begin(), myVector.end(), itr);
}

vector<int> LoadAllTokens(string filename) {
	vector<int> allTokens;
	ifstream input(filename.c_str());
	if (!input.is_open())
		cerr << "Couldn't open the file" << endl;

	istream_iterator<int> itr(input);
	istream_iterator<int> eos;

	while (true) {
		if (itr == eos)
			break;
		allTokens.push_back(*itr);
		itr++;
	}

	return allTokens;
}