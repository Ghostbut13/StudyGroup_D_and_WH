#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>  // 确保这行存在
#include <numeric>
#include <iterator>
using namespace std;  // 确保这行存在


vector<string> LoadAllTokens(string filename);
void Biasedsort(vector<string>&);
bool mySort(string a, string b);

int main() {
	string filename = "../MeFirst.txt";
	vector<string> allTokens;
	allTokens = LoadAllTokens(filename);
	Biasedsort(allTokens);
	for (vector<string>::iterator itr = allTokens.begin(); itr != allTokens.end(); ++itr) {
		cout << *itr << endl;
	}
	return 0;
}


// Biasedsort 函数实现了一个偏向性排序
void Biasedsort(vector<string>& myString) {
    // 使用 std::sort 函数对 vector 进行排序
    std::sort(myString.begin(),  // 排序范围的开始
              myString.end(),    // 排序范围的结束
              // 使用 lambda 表达式定义自定义比较函数
              [](const string& a, const string& b) {
                  // 如果字符串 a 是 "MeFirst"，它应该排在前面
                  if (a == "MeFirst") return true;
                  // 如果字符串 b 是 "MeFirst"，它不应该排在前面
                  if (b == "MeFirst") return false;
                  // 对于其他情况，按字母顺序排序
                  return a < b;
              });
}

// bool mySort(const string& a, const string& b) {
//     if (a == "MeFirst") return true;
//     if (b == "MeFirst") return false;
//     return a < b;
// }


vector<string> LoadAllTokens(string filename) {
	vector<string> allTokens;
	ifstream input(filename.c_str());
	if (!input.is_open())
		cerr << "Couldn't open the file" << endl;

	istream_iterator<string> itr(input);
	istream_iterator<string> eos;

	while (true) {
		if (itr == eos)
			break;
		allTokens.push_back(*itr);
		itr++;
	}

	return allTokens;
}
