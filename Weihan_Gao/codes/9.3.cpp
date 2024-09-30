#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

double DistanceToOrigin(vector<double>);
double square(double);


int main() {
	vector<double> myN;
	myN.push_back(5.0);
	myN.push_back(12.0);
	double result = DistanceToOrigin(myN);
	cout << result << endl;
}


double DistanceToOrigin(vector<double> N) {
	transform(
		N.begin(),
		N.end(),
		N.begin(),
		square
	);
	return sqrt(accumulate(N.begin(), N.end(), 0.0));
}
double square(double a) {
	return a * a;
}