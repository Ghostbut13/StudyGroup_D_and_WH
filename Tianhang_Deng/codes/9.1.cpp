#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>
using namespace std;

void PrintVector(vector<int> myvec)
{
    //ostream_iterator<int> myitr(cout, " ");
    copy(myvec.begin(), myvec.end(), ostream_iterator<int>(cout, " "));  
    // Shouldn't write the code like this: ostream_iterator<int>(cout, " ")
}


int main()
{
    int N = 8;
    vector<int> myvec(N);
    generate(myvec.begin(), myvec.end(), rand);  // No changes
    PrintVector(myvec);
    return 0;
}