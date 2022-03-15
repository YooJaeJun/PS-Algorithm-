#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	getline(cin, s);
	int n = 1;
	if (s.size() >= 2) {
		for (int i = 1; i != s.size() - 1; i++) {
			if (s[i] == ' ') {
				n++;
			}
		}
	}
	if (s[0] == ' ' && s.size() == 1) {	//입력이 공백 1개일 경우
		cout << n - 1;
	}
	else {
		cout << n;
	}
	return 0;
}