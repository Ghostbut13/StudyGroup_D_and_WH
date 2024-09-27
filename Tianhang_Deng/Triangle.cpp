#include <iostream>
#include <iomanip>
using namespace std;

void DrawTriangle(int height, char build)     
{
    // An input error checking-system should be realised
    int Bottom_char_num = 2*height-1;
    int Top_white_num_H = (Bottom_char_num-1)/2;
    for(int h = 1; h <= height; ++h)
    {
        cout << setw(Top_white_num_H) << "";
        cout << setfill(build) << setw(2*h-1) << "" << setfill(' ') << endl;
        Top_white_num_H = Top_white_num_H-1;
    }
}

int main()
{
    int height = 8;
    char build = '#';
    DrawTriangle(height,build);
    return 0;
}