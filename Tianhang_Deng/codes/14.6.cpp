#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <iterator>
using namespace std;

string GetLine()
{
string result;
getline(cin, result);
return result;
}

template <typename ValueType>
inline ValueType GetValue(string message)    // So the ValueType here is not output
{
    while(true) // Read input until user enters valid data
    {
        stringstream converter;
        converter << GetLine();
        /* Try reading an int, continue if we succeeded. */
        int result;
        converter >> result;
        if(!converter.fail())
        {
            char remaining;
            converter >> remaining; // Check for stray input
            if(converter.fail()) // Couldn't read any more, so input is valid
            return result;
            else cout << message << endl;
        }
        else cout << message << endl;
        cout << "Retry: ";
    }
}

int main()
{
    string message = "Need an integer";
    GetValue<int>(message);
    return 0;
}
