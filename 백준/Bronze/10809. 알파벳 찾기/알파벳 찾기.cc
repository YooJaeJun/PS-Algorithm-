#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v(26, -1);
	string s;
	cin >> s;
	for (int i = 0; i != s.size(); i++) {
		if (v[s[i] - 'a'] == -1) {	//a는 v의 0번째, b는 1번째..
			v[s[i] - 'a'] = i;
		}
	}
	for (const auto& elem : v) {
		cout << elem << ' ';
	}
	return 0;
}