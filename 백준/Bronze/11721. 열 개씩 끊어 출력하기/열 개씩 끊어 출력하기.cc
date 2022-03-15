#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	getline(cin, s);
	for (int i = 0; i != s.size(); i++) {
		cout << s[i];
		if ((i + 1) % 10 == 0) {
			puts("");
		}
	}
	return 0;
}