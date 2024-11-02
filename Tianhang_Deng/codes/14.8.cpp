#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

template <typename ValueType>
inline void Clamp(ValueType& value,ValueType lower,ValueType upper)
{
    if(value >= lower && value <= upper)
        return;
    else
        {
            value = lower;
            return;
        }
}

int main()
{
    int value = 1, lower = 34, upper = 100;
    Clamp(value,lower,upper);
    cout << value << endl;
    return 0;
}