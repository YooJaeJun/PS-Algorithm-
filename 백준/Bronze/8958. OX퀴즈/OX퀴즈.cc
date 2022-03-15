#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	string s;
	for (int i = 0; i != t; i++) {
		cin >> s;
		int score = 0;
		int num = 1;
		for (const auto& elem : s) {
			if (elem == 'O') {
				score += num++;
			}
			else {
				num = 1;
			}
		}
		cout << score << endl;
	}
	return 0;
}