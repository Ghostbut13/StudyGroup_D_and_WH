#include <iostream>
#include <fstream>
#include <map>
#include <vector>
using namespace std;

vector<string> LoadAllTokens(string filename);
multimap<string, string> InvertMap(multimap<string, string>);

int main() {

	//initialize multimap
	string filename1 = "stringTokens.txt";
	string filename2 = "7_1.txt";
	vector<string> myVector1, myVector2;
	myVector1 = LoadAllTokens(filename1);
	myVector2 = LoadAllTokens(filename2); //longer
	multimap<string, string> myMap;
	vector <string>::iterator itr2 = myVector2.begin();
	for (vector <string>::iterator itr1 = myVector1.begin(); itr1 != myVector1.end(); ++itr1) {
		myMap.insert(make_pair(*itr1, *itr2));
		++itr2;
	}

	//// show it if oyou want
	//for (multimap<string, string>::iterator itr = myMap.begin(); itr != myMap.end(); ++itr) {
	//	cout << itr->first << " -> " << itr->second << endl;
	//}

	// inverse
	multimap<string, string> MyInvertMap = InvertMap(myMap);
	//MyInvertMap = InvertMap(MyInvertMap);

	//COUNT


}


multimap<string, string> InvertMap(multimap<string, string> myMap) {
	multimap<string, string> MyInvertMap;
	for (multimap<string, string>::iterator itr = myMap.begin(); itr != myMap.end(); ++itr) {
		MyInvertMap.insert(make_pair(itr->second,itr->first));
	}
	return MyInvertMap;
}

vector<string> LoadAllTokens(string filename) {
	vector<string> allTokens;
	ifstream input(filename.c_str());
	/*if (!input.is_open())
		cerr << "Couldn't open the file" << endl;*/

	istream_iterator<string> itr(input);
	istream_iterator<string> eos;

	while (true) {
		if (itr == eos)
			break;
		allTokens.push_back(*itr);
		itr++;
	}
	input.close();

	return allTokens;
}

