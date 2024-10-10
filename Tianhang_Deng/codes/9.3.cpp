#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std;

double SqCalculation(double i)   // SquareCalculation would be wrong
{
    return (i*i);
}

double DistanceToOrigin(vector<double>& points)
{
    transform(points.begin(), points.end(), points.begin(), SqCalculation);
    double sum = accumulate(points.begin(), points.end(), 0);
    double result = sqrt(sum);
    return result;
}

int main()
{
    vector<double> points;
    points.push_back(2.3);
    points.push_back(3.3);
    points.push_back(12.3);
    points.push_back(2.23);
    points.push_back(2.13);
    points.push_back(0.3);
    double result = DistanceToOrigin(points);
    cout << result;
    return 0;
}