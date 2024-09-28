#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
using namespace std;

vector<char> LoadAllTokens(string Filename)    // The vector is char, but can it be string?(,which can not use push_back)
{
    vector<char> output;
    ifstream mystream(Filename.c_str());     // Using the ifstream to open the file (Is there any way not to use ifstream?)
    if(!mystream.is_open())
    {
        cerr << "Couldn't open the file" << endl;
        mystream.clear();
    }
    else
    {
        istream_iterator<char> itr(mystream);  // mystream as the input of the iterator adapter
        istream_iterator<char> enditr;        // End iterator
        while(true)//for(int i = 0; i <= 40; ++i)
        {
            if(itr != enditr)
            {
                output.push_back(*itr);    // Read the content from file into vector (use at.() is illegal for 0 size vector)
                ++itr;
            }
            else
            {
                mystream.close();      // If to the end, close the file and push the output return
                return output;
            }
        }
    }
}

int main()
{
    string Filename = "test.txt";
    vector<char> output = LoadAllTokens(Filename);
    for(vector<char>::iterator itr = output.begin(); itr != output.end(); ++itr)  // Display the result
    {
        cout << *itr << endl; 
    }
    cout << output.size() << endl;
    return 0;
}