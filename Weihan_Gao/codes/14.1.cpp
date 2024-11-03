#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

template <typename InputIterator, typename OutputIterator, typename Function>
inline OutputIterator Mycopy_if(InputIterator start,
                              InputIterator end,
                              OutputIterator where,
                              Function fn)
{
    while (start != end)
    {
        if (fn(*start)==1)
        {
            *where = *start;
        }
        ++where;
        ++start;
        
    }
    return where;
    
}

bool IsEven(int a){
    if ((a % 2) == 0)
    {
        return 1;
    }
    else return 0;
    
}

int main(){
    vector<int> v={0,1,2,3,4,5}; 
    Mycopy_if(v.begin(), v.end(), ostream_iterator<int>(cout," "), IsEven);
    return 0;
}