#include <iostream>
#include <vector>
#include <ctime>

using namespace std;


int main() {
	vector<int> myVector1, myVector2, myVector3;
	double t1, t2;
	for (int i = 0; i < 10000000 ;++i) {
		myVector1.push_back(i); // initialize
	}

	//block_insert
	clock_t startT = clock();
	myVector2.insert(myVector2.begin(), myVector1.rbegin(), myVector1.rend());
	t1 = static_cast<double>(clock() - startT) / CLOCKS_PER_SEC;

	//element_pop_push
	startT = clock();
	for (int i = 0; i < 10000000; ++i) {
		myVector3.push_back(myVector1.back());
		myVector1.pop_back();
	}
	t2 = static_cast<double>(clock() - startT) / CLOCKS_PER_SEC;

	//compare
	if(myVector2 == myVector3) // make sure vector3=vector2=reverse(vector1)
		cout << "block_insert : element_pop_push = " << t1 << " " << t2 << endl;

	return 0;
}
