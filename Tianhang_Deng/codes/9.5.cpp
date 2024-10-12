#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;

set<string> CriticsPick(map<string, double>& movie)
{
    multimap<double, string> New_list;
    set<string> result;
    for(map<string, double>::iterator itr = movie.begin(); itr != movie.end(); ++itr)
        New_list.insert(make_pair(itr->second, itr->first));    // Move to multimap first
// Then do the thing
    if(movie.size()<=10)
    {
        for(multimap<double, string>::iterator itr2 = New_list.begin(); itr2 != New_list.end(); ++itr2)
        {
            result.insert(itr2->second);
        }
    }
    else
    {
        for(multimap<double, string>::reverse_iterator itr3 = New_list.rbegin(); itr3 != New_list.rend(); ++itr3)
        {
            result.insert(itr3->second);
            if(result.size()==10)
                return result;
        }
    }
}

int main()
{
    map<string, double> movie;
    movie.insert(make_pair("dwh",0.0));
    movie.insert(make_pair("gwh",3.0));
    movie.insert(make_pair("i love gwh",3.4));
    movie.insert(make_pair("gwh loves me",1.9));
    movie.insert(make_pair("gwh loves moonshine",3.4));
    movie.insert(make_pair("gwh vs. wolfman",0.0));
    movie.insert(make_pair("gwhasda",1.7));
    movie.insert(make_pair("gwh dsda",2.8));
    movie.insert(make_pair("gwh vs. wolfdsn",5.3));
    movie.insert(make_pair("gwh vs. wodsdlfman",4.1));
    movie.insert(make_pair("gwh vs. woldsadfman",2.4));
    movie.insert(make_pair("gwh adsadman",3.3));
    movie.insert(make_pair("gwhdsadolfman",6.0));
    movie.insert(make_pair("gwh vdsdolfman",3.1));
    movie.insert(make_pair("gwdadsan",5.0));

    set<string> result = CriticsPick(movie);
    for(set<string>::iterator itr = result.begin(); itr != result.end(); ++itr)
        cout << *itr << endl;
    return 0;
}

