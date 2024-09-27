#include <iostream>
#include <fstream>
using namespace std;

string GetLine()     //The function for file name from console
{
    string result;
    getline(cin,result);
    return result;
}


void OpenFile(string Filename)
{
    ifstream mystream(Filename.c_str());
    if(!mystream.is_open())
    {
        cerr << "Couldn't open the file" << endl;
        mystream.clear();
    }
    else
    {
        string result;
        mystream >> result;
        cout << result;
    }
    return;
}

/*
void OpenFile(ifstream& input)
{
    cout << "Give the name of file:";
    input.open(GetLine().c_str());
    if(!input.is_open())
    {
        cerr << "Couldn't open the file" << endl;
        input.clear();
    }
    return;
}
*/
int main()
{
    /*
    ifstream input;
    OpenFile(input);
    */
    cout << "Give the name of file:";
    string input;
    input = GetLine();
    OpenFile(input);
    /*
    string result;
    input >> result;
    cout << result;
    */
}