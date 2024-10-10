#include <iostream>
#include <set>
#include <vector>
using namespace std;

void PrintMatchingPrefixes(set<string> myset, string prefix)
{
    set<string>::iterator stop = myset.upper_bound(prefix + "zzzzzzzz");    // It works!!!!! But limited
    for(set<string>::iterator itr = myset.lower_bound(prefix); itr != stop; ++itr)
        cout << *itr << endl;
}

int main()   // 差一点就搞成了string与char的数据类型转换
{
    set<string> myset;
    myset.insert("gwh, i love you");
    myset.insert("dwh is good");
    myset.insert("gwh, you are my sunshine");
    myset.insert("dwh, there is nothing other puppies but you in my heart");
    myset.insert("dwhzaaazzzzzaazzdsadadasda");
    string prefix = "dwh";
    PrintMatchingPrefixes(myset, prefix);
}