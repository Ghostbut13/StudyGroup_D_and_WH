#include <iostream>
#include <deque>
#include <vector>
using namespace std;

string VigenereEncrypt(string text, deque<int>& keys)
{
    int s = text.size();
    for(int i = 0; i <= s-1; ++i)  // Mistake: s; The first index is 0 not 1
    {
        if(text.at(i)!=32)      // The char is not space; Mistake:!=    So, what is "if(!text.at(i)==32)"
        {
            if(text.at(i)+keys.at(0) > 122)    // The char whould exceed the 'z'?
                text.at(i) = 96+text.at(i)+keys.at(0)-122;
            else text.at(i) = text.at(i)+keys.at(0);
            keys.push_back(keys.at(0));
            keys.pop_front();
        }
    }
    return text;
}

int main()
{
    deque<int> keys(3);
    keys.at(0) = 1;
    keys.at(1) = 3;
    keys.at(2) = 7;

    string text = "The cookies are in the fridge";
    string result = VigenereEncrypt(text, keys);
    cout << "Vigenère cipher:" << " " << result << endl;
    return 0;
}