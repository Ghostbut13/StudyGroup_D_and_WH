#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
using namespace std;

string GetLine()     //The function for reading message from console
{
    string result;
    getline(cin,result);
    return result;
}

string ExtractFirstToken()
{
    while(true)
    {
        stringstream mystream;
        mystream << GetLine();
        string output;
        mystream >> output;

        if(!mystream.fail())      //Error control, check the format of input
        {
            int failure;
            mystream >> failure;
            if(mystream.fail())
            {
                cout << output << endl;
                return output;
            }
            else cout << "Unexpected input:" << failure << endl;
        }
        else cout << "Please enter string." << endl;
        cout << "Retry:";
    }
}

int main()
{
    cout << "Please enter string." << endl;
    ExtractFirstToken();
    return 0;
}