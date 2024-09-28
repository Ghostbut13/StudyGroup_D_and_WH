#include <iostream>
#include <ctime>
#include <vector>
#include <deque>
using namespace std;


int main()
{
	size_t N = 10000, R = 1000000, I = 80000;
	double t1, t2, t3;
	clock_t startT1, startT2, startT3;
	cout << "Original size: " << N << endl;
	cout << "Reversed size: " << R << endl;
	cout << "Inserted size: " << I << endl;
	
	vector<string> myVector(N, "CS106B");
	vector<string> myVectorWithR(N, "CS106B");
	deque<string> myDeque(N, "CS106B");
	myVectorWithR.reserve(R);

	startT1 = clock();
	myVector.insert(myVector.begin()+5000,I, "X");
	t1 = static_cast<double>(clock() - startT1) / CLOCKS_PER_SEC;

	startT2 = clock();
	myVectorWithR.insert(myVectorWithR.begin()+5000,I, "X");
	t2 = static_cast<double>(clock() - startT2) / CLOCKS_PER_SEC;

	startT3 = clock();
	myDeque.insert(myDeque.begin()+5000,I, "X");
	t3 = static_cast<double>(clock() - startT3) / CLOCKS_PER_SEC;


	cout << "vector : vectorWithR : Deque = " << t1 << "  " << t2 << "  " << t3 << endl;

}