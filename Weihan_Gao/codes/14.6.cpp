#include <iostream>
#include <string>
#include <sstream> 
using namespace std;

inline string GetLine() {
    string result;
    getline(cin, result);
    return result;
}

template <typename VauleType> VauleType GetValue(string type) {
    while (true)
    {
        stringstream converter;
        converter << GetLine();

        VauleType result;
        converter >> result;

        if (!converter.fail()) {
            char remaining;
            converter >> remaining;

            if (converter.fail()) {
                return result;
            }
            else cout << "non-expected char" << endl;
        }
        else cout << "Please return" << type << endl;
        cout << "Retry :";
    }

}

int main() {
    int a = GetValue<int>("an integer");
    cout << a << endl;
    return 0;
}