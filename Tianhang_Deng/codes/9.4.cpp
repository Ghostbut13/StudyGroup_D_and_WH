#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// Rather use deque than vector
void BiasedSort(vector<string>& text)
{
    int num = 0;
    int s = text.size();
    vector<string>::iterator special;
    for(int i = 0; i != s; ++i)      // Find out the "Me First" first, then swap them to the front side
    {
        special = find(text.begin()+num,text.end(),"Me First");
        if(special != text.end())
        {
            swap(text.at(num), *special);
            ++num;
        }
        else
            break;
    }
    sort(text.begin()+num,text.end());
}

int main()
{
    vector<string> text;
    text.push_back("hello");
    text.push_back("The cookies are in the fridge");
    text.push_back("Me First");
    text.push_back("AAA");
    text.push_back("Me First");
    text.push_back("ahe cookies are in the fridge");
    text.push_back("dwh");
    text.push_back("Me First");
    BiasedSort(text);
    for(vector<string>::iterator itr = text.begin(); itr != text.end(); ++itr)
        cout << *itr << endl;
    return 0;
}