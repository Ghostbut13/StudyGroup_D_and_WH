#include <iostream>
#include <map>
#include <deque>
#include <utility>
using namespace std;

int NumberDuplicateEntries(map<string, string>& mymap)
{
    deque<string> value;
    for(map<string, string>::iterator itr = mymap.begin(); itr != mymap.end(); ++itr)
    {
        value.push_front(itr->second);       // Take out all the values from map and construct a deque
    }
    int result = 0;
    deque<string>::iterator itr_v = value.begin();
    int size = value.size();
    int new_size = value.size();
    for(int j = 1; j <= size; ++j)
    {
        for(int i = 1; i < new_size; ++i)
        {
            if(*itr_v == value.at(i))
            {
                result = result+1;
            }
        }
        ++itr_v;
        value.pop_front();
        new_size = value.size();
    }

    return result;
}

int main()
{
    map<string, string> mymap;
    mymap.insert(make_pair("a","c"));
    mymap.insert(make_pair("b","bc"));
    mymap.insert(make_pair("c","abc"));
    mymap.insert(make_pair("d","ac"));
    mymap.insert(make_pair("e","abc"));
    mymap.insert(make_pair("f","abc"));
    int result = NumberDuplicateEntries(mymap);
    cout << result << endl;
    return 0;
}