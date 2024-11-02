#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
using namespace std;

bool IsEven(int a)
{
    return (a % 2 == 0);
}

int main()
{
    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(8);
    v.push_back(6);
    copy_if(v.begin(), v.end(), ostream_iterator<int>(cout, " "), IsEven);
    return 0;
}