#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;

// 不考虑大写字母
string MonoalphabeticSubstitutionEncrypt(string text)
{
    vector<char> alphabet(26);
    int i = 97;
    for(vector<char>::iterator itr = alphabet.begin(); itr != alphabet.end(); ++itr)
    {
        *itr = i;
        ++i;
    }
    random_shuffle(alphabet.begin(), alphabet.end());   // Shuffle the alphabet

    i = 97;
    map<char, char> list;
    for(int a = 0; a != 26; ++a)
    {
        list.insert(make_pair(i,alphabet.at(a)));   // Build the mapping list
        ++i;
    }

    int s = text.size();
    for(int i = 0; i <= s-1; ++i)
    {
        if(text.at(i)!=32)
        {
            char check = text.at(i);
            text.at(i) = list.find(check)->second;    // Cipher generated
        }
    }
    return text;
}

int main()
{
    string text = "The cookies are in the fridge";
    string result = MonoalphabeticSubstitutionEncrypt(text);
    cout << "monoalphabetic substitution cipher:" << " " << result << endl;
    return 0;
}