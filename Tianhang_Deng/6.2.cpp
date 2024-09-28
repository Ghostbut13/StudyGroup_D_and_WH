#include <iostream>
#include <vector>
using namespace std;

vector<int> DuplicateReversed(vector<int>& input)
{
    vector<int> output;
    /* Print a vector backwards */
    for(vector<int>::reverse_iterator r_itr = input.rbegin(); r_itr != input.rend(); ++r_itr)
    {
        output.push_back(*r_itr);
    }
    return output;
}

int main()
{
    vector<int> input;
    for(int i = 0; i <= 9; ++i)   // Are there some faster ways to initialize the vector than that in for loop?
    {
        input.push_back(i);
    }

    vector<int> output = DuplicateReversed(input);
    for(vector<int>::iterator itr = output.begin(); itr != output.end(); ++itr)  // Display the result
    {
        cout << *itr; 
    }
    //cout << output << endl;      Illegal syntax?
    return 0;
}