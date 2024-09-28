#include <iostream>
#include <iomanip>
using namespace std;


void DrawTriangle();

int main() {
	DrawTriangle();
}
	
	
void DrawTriangle() {
	size_t Height; 
	char Symbol;
	cin >> Height;
	cin >> Symbol;

	//cout<< Height <<""<< Symbol << endl;
	for (size_t i = 0; i < Height; ++i)
		cout << setw(Height - i - 1) << "" << setfill(Symbol) << setw(2 * i + 1) << "" << setfill(' ') << setw(Height - i - 1) << "" << endl;
}