#include <iostream>
#include <sstream>
#include <string>
using namespace std;

string GetLine()     //The function for reading message from console
{
    string result;
    getline(cin,result);
    return result;
}

double GetReal()
{
    while(true) // Read input until user enters valid data
    {
        stringstream converter;
        converter << GetLine();
        /* Try reading an int, continue if we succeeded. */
        double result;
        converter >> result;
        if(!converter.fail())
        {
            char remaining;
            converter >> remaining; // Check for stray input
            if(converter.fail()) // Couldn't read any more, so input is valid
            {
                cout << result << endl;
                return result;
            }
            else cout << "Unexpected character: " << remaining << endl;
        }
        else cout << "Please enter a double." << endl;
        cout << "Retry: ";
    }
}

int main()
{
    cout << "Please enter Real:" << endl;
    GetReal();
    return 0;
}