#include <iostream>
#include <fstream>
#include <set>
using namespace std;

set<string> LoadAllTokens(string filename);
set<string> PrintMatchingPrefixes(set<string>, string);


int main() {

	//initialize multimap
	string filename1 = "7_1.txt";
	set<string> mySet;
	mySet = LoadAllTokens(filename1);
	/*for (set<string>::iterator itr = mySet.begin(); itr != mySet.end(); ++itr) {
		cout << *itr << endl;
	}*/

	
	//prefix = "fi"
	string prefix = "fi";
	set<string> subSet = PrintMatchingPrefixes(mySet,prefix);
	for (set<string>::iterator itr = subSet.begin(); itr != subSet.end(); ++itr) {
		cout << *itr << endl;
	}

}

set<string> PrintMatchingPrefixes(set<string> mySet, string pre) {
	set<string> mySetWithPrefix = mySet;
	set<string> subSet;
	mySetWithPrefix.insert(pre);
	string nextPrefix = pre;
	*(nextPrefix.rbegin())= *(nextPrefix.rbegin())+1;
	mySetWithPrefix.insert(nextPrefix);
	for (set<string>::iterator itr = mySetWithPrefix.upper_bound(pre); itr != mySetWithPrefix.lower_bound(nextPrefix); ++itr) {
		subSet.insert(*itr);
	}
	return subSet;
}


set<string> LoadAllTokens(string filename) {
	set<string> allTokens;
	ifstream input(filename.c_str());
	/*if (!input.is_open())
		cerr << "Couldn't open the file" << endl;*/

	istream_iterator<string> itr(input);
	istream_iterator<string> eos;

	while (true) {
		if (itr == eos)
			break;
		allTokens.insert(*itr);
		itr++;
	}
	input.close();

	return allTokens;
}

