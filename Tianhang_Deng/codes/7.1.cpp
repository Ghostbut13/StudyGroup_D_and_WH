#include <iostream>
#include <map>
#include <ctime>
#include <utility>
using namespace std;

int main()
{
    map<int, int> mymap_insert;
    map<int, int> mymap_bracket;

    clock_t start_insert = clock();
    for(int i = 0; i <= 20000; ++i)
    {
        mymap_insert.insert(make_pair(i,20000));        // insert part
    }
    clock_t duration_insert = clock() - start_insert;
    cout << "Durations:" << static_cast<double>(duration_insert) / CLOCKS_PER_SEC << " " << "seconds" << endl;

    clock_t start_bracket = clock();
    for(int i = 0; i <= 20000; ++i)
    {
        mymap_bracket[i] = 20000;                     // bracket part
    }
    clock_t duration_bracket = clock() - start_bracket;
    cout << "Durations:" << static_cast<double>(duration_bracket) / CLOCKS_PER_SEC << " " << "seconds" << endl;

    // <int, string>
    map<int, string> mymap_insert2;
    map<int, string> mymap_bracket2;

    clock_t start_insert2 = clock();
    for(int i = 0; i <= 20000; ++i)
    {
        mymap_insert2.insert(make_pair(i,"fsdgsdgsegsdsdgsdvrege"));       // insert part
    }
    clock_t duration_insert2 = clock() - start_insert2;
    cout << "Durations:" << static_cast<double>(duration_insert2) / CLOCKS_PER_SEC << " " << "seconds" << endl;

    clock_t start_bracket2 = clock();
    for(int i = 0; i <= 20000; ++i)
    {
        mymap_bracket2[i] = "fsdgsdgsegsdsdgsdvrege";               // bracket part
    }
    clock_t duration_bracket2 = clock() - start_bracket2;
    cout << "Durations:" << static_cast<double>(duration_bracket2) / CLOCKS_PER_SEC << " " << "seconds" << endl;

    return 0;
}