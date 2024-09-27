#include <iostream>
#include <ctime>
#include <vector>
#include <deque>
using namespace std;


int main()
{
	size_t N = 10000;
	double t1, t2, t3;
	clock_t startT1, startT2, startT3;
	string s1, s2;

	vector<string> myVector(N, "CS106B");

	//startT1 = clock();
	//for (size_t i = 0; i < 20000000; ++i)
	//	s1 = myVector[0];
	//t1 = static_cast<double>(clock() - startT1) / CLOCKS_PER_SEC;

	//startT2 = clock();
	//for (size_t j = 0; j < 20000000; ++j)
	//	s2 = myVector.at(0);
	//t2 = static_cast<double>(clock() - startT2) / CLOCKS_PER_SEC;

	//cout << "[] : at = " << t1 << "  " << t2 << endl;

	//
	//
	//s1 = myVector[N+200];
	//s2 = myVector.at(N + 1000);


}