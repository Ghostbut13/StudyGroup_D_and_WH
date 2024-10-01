#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <utility>
using namespace std;

int NumberDuplicateEntries(map<string, string>& mymap)
{
    set<string> value;
    multiset<string> myMul;
    for (map<string, string>::iterator itr = mymap.begin(); itr != mymap.end(); ++itr)
    {
        value.insert(itr->second);       // Take out all the values from map and construct a deque
        myMul.insert(itr->second);
    }

    int result = 0;
    for (set<string>::iterator i = value.begin(); i != value.end(); ++i) {
        if (myMul.count(*i) > 1)
            result += myMul.count(*i);
    }

    return result;
}

int main()
{
    map<string, string> mymap;
    mymap.insert(make_pair("a", "abc"));
    mymap.insert(make_pair("b", "a"));
    mymap.insert(make_pair("c", "abc"));
    mymap.insert(make_pair("d", "a"));
    mymap.insert(make_pair("e", "abc"));
    mymap.insert(make_pair("f", "abc"));


    int result = NumberDuplicateEntries(mymap);
    cout << result << endl;
    return 0;
}