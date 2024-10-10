#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

bool StrLength(string str)
{
    return (str.size() <= 3);
}

vector<string> RemoveShortWords(vector<string>& mystring)
{
    mystring.erase(remove_if(mystring.begin(), mystring.end(), StrLength), mystring.end());
    return mystring;
}

int main()
{
    vector<string> mystring;
    mystring.push_back("gwh");
    mystring.push_back("gwhdsadad");
    mystring.push_back("dwh");
    mystring.push_back("gwdsaddd");
    mystring.push_back("b");
    mystring.push_back("asdad");
    mystring.push_back("aa");
    vector<string> result;
    result = RemoveShortWords(mystring);
    for(vector<string>::iterator itr = result.begin(); itr != result.end(); ++itr)
        cout << *itr << endl;
    return 0;
}