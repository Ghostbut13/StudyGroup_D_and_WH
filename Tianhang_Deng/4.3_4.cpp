#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
using namespace std;

int main()
{
    vector<string> mystring(5);
    vector<string> mystring_R(5);
    deque<string> mydeque(5);
    mystring_R.reserve(20000);
    string A = "sfjsdkfsjkdfdcxvvxdnsdjf";
    int num_add = 20000;
    
    /* For the adding at the end
    // Loop for the vec without reserve
    clock_t start = clock();
    for(int i = 1; i <= num_add; ++i)
    {
        mystring.push_back(A);
    }
    clock_t duration = clock() - start;
    cout << "Durations:" << static_cast<double>(duration) / CLOCKS_PER_SEC << " " << "seconds" << endl;

    // Loop for the vec with reserve
    clock_t start_R = clock();
    for(int i = 1; i <= num_add; ++i)
    {
        mystring_R.push_back(A);
    }
    clock_t duration_R = clock() - start_R;
    cout << "Durations_R:" << static_cast<double>(duration_R) / CLOCKS_PER_SEC << " " << "seconds" << endl;

    // Loop for the deque
    clock_t start_d = clock();
    for(int i = 1; i <= num_add; ++i)
    {
        mydeque.push_back(A);
    }
    clock_t duration_d = clock() - start_d;
    cout << "Durations_d:" << static_cast<double>(duration_d) / CLOCKS_PER_SEC << " " << "seconds" << endl;
    */
    
    // Loop for the vec without reserve
    clock_t start = clock();
    for(int i = 1; i <= num_add; ++i)
    {
        mystring.insert(mystring.begin(), A);
    }
    clock_t duration = clock() - start;
    cout << "Durations:" << static_cast<double>(duration) / CLOCKS_PER_SEC << " " << "seconds" << endl;

    // Loop for the vec with reserve
    clock_t start_R = clock();
    for(int i = 1; i <= num_add; ++i)
    {
        mystring_R.insert(mystring_R.begin(), A);
    }
    clock_t duration_R = clock() - start_R;
    cout << "Durations_R:" << static_cast<double>(duration_R) / CLOCKS_PER_SEC << " " << "seconds" << endl;

    // Loop for the deque
    clock_t start_d = clock();
    for(int i = 1; i <= num_add; ++i)
    {
        mydeque.push_front(A);
    }
    clock_t duration_d = clock() - start_d;
    cout << "Durations_d:" << static_cast<double>(duration_d) / CLOCKS_PER_SEC << " " << "seconds" << endl;

    cout << mystring.size() << endl;
    cout << mystring_R.size() << endl;
    cout << mydeque.size() << endl;
    return 0;
}