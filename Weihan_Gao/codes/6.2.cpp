#include <iostream>
#include <vector>

using namespace std;

vector<int> DuplicateReversed(vector<int> myVector1);

int main() {
	vector<int> myVector1, myVector2;
	for (int i = 0; i < 10000000 ;++i) {
		myVector1.push_back(i);
	}

	myVector2 = DuplicateReversed(myVector1);
	/*for (vector<int>::iterator itr = myVector2.begin(); itr != myVector2.end(); ++itr)
		cout << *itr << endl;
	return 0;*/
}

vector<int> DuplicateReversed(vector<int> myVector1) {
	vector<int> myVector2;
	myVector2.insert(myVector2.begin(),myVector1.rbegin(),myVector1.rend());
	return myVector2;
}