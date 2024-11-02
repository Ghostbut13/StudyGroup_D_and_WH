#include <iostream>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <iterator>
using namespace std;

template <typename InputIterator1, typename InputIterator2>
inline bool ranges_are_equal(InputIterator1 start1,InputIterator1 end1,InputIterator2 start2,InputIterator2 end2)
{
    while(start1 != end1 && start2 != end2)
    {
        if(*start1 != *start2) return false;
        ++start1;
        ++start2;
        if(start1 == end1 && start2 != end2) return false;
        if(start1 != end1 && start2 == end2) return false;
        if(start1 == end1 && start2 == end2) return true;
    }
}

 int main()
 {
    ifstream input1("file1.txt");
    ifstream input2("file2.txt");
    if(ranges_are_equal(istreambuf_iterator<char>(input1),istreambuf_iterator<char>(),istreambuf_iterator<char>(input2),istreambuf_iterator<char>()))
        cout << "equal" << endl;
    else
        cout << "not equal" << endl;
    return 0;
 }