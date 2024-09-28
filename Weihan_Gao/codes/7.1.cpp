#include <iostream>
#include <map>
#include <ctime>
using namespace std;

int main() {
	/*double t1, t2;
	map<int, int> myMap1, myMap2;
	clock_t startT1,startT2;


	startT1 = clock();
	for (int i = 0; i < 100000; ++i) {
		myMap1.insert(make_pair(i,i*2));
	}
	t1 = static_cast<double>(clock() - startT1) / CLOCKS_PER_SEC;

	startT2 = clock();
	for (int i = 0; i < 100000; ++i) {
		myMap2[i]= i * 2;
	}
	t2 = static_cast<double>(clock() - startT2) / CLOCKS_PER_SEC;

	if (myMap1 == myMap2)
		cout << "insert : [] " << t1 << " " << t2 << endl;*/


	string filename = "stringTokens.txt";
	vector<string> allTokens;
	allTokens = LoadAllTokens(filename);
	
	double t1, t2;
	map<int, string> myMap1, myMap2;
	clock_t startT1, startT2;
	int i = 0;
	int j = 0;

	startT1 = clock();
	for (int k = 0; k < 1000; ++k) {
		for (vector<string>::iterator itr = allTokens.begin(); itr != allTokens.end(); ++itr) {
			myMap1.insert(make_pair(i, *itr));
			++i;
		}
	}
	t1 = static_cast<double>(clock() - startT1) / CLOCKS_PER_SEC;

	startT2 = clock();
	for (int k = 0; k < 1000; ++k) {
		for (vector<string>::iterator itr = allTokens.begin(); itr != allTokens.end(); ++itr) {
			myMap2[j] = *itr;
			++j;
		}
	}
	t2 = static_cast<double>(clock() - startT2) / CLOCKS_PER_SEC;


	
	//for (map<int, string>::iterator itr = myMap1.begin(); itr != myMap1.end(); ++itr) {
	//	cout << itr->first << "->" << itr->second << endl;
	//}
	//for (map<int, string>::iterator itr = myMap2.begin(); itr != myMap2.end(); ++itr) {
	//	cout << itr->first << "->" << itr->second << endl;
	//}

	if (myMap1 == myMap2)
		cout << "insert : [] " << t1 << " " << t2 << endl;



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


