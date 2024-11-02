#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <iterator>
using namespace std;

template <typename TargetType>
inline TargetType Lexical_cast(string toConvert)    // So the ValueType here is not output
{
    stringstream converter;
    converter << toConvert;
    /* Try reading an int, continue if we succeeded. */
    TargetType result;
    converter >> result;
    if(!converter.fail())
    {
        char remaining;
        converter >> remaining; // Check for stray input
        if(converter.fail()) // Couldn't read any more, so input is valid
        return result;
        else cout << "Remaining Prblem" << endl;
    }
    else cout << "Error" << endl;
}

int main()
{
    string toConvert = "45";
    int result = Lexical_cast<int>(toConvert);
    cout << result << endl;
    return 0;
}