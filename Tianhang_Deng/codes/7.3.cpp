#include <iostream>
#include <map>
#include <utility>
using namespace std;

multimap<string, string> InvertMap(multimap<string, string>& mymap)  
// Big Mistake: multimap InvertMap(multimap<string, string>& mymap)
{
    multimap<string, string> result;
    for(multimap<string, string>::iterator itr = mymap.begin(); itr != mymap.end(); ++itr)
    {
        result.insert(make_pair(itr->second,itr->first));
    }
    return result;
}

int main()
{
    multimap<string, string> mymap;
    mymap.insert(make_pair("a","c"));
    mymap.insert(make_pair("b","bc"));
    mymap.insert(make_pair("aa","abc"));
    mymap.insert(make_pair("a","ac"));
    mymap.insert(make_pair("e","abc"));
    mymap.insert(make_pair("f","abc"));
    multimap<string, string> result = InvertMap(mymap);
    for(multimap<string, string>::iterator itr = result.begin(); itr != result.end(); ++itr)
        cout << itr->first << ": " << itr->second << endl;
    return 0;
}