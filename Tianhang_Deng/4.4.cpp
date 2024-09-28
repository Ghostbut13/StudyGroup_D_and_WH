#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> myint_bracket(5);
    vector<int> myint_at(5);
    int a = myint_bracket[0];
    int b = myint_at.at(0);
    cout << a << endl;
    cout << b << endl;
    return 0;
}