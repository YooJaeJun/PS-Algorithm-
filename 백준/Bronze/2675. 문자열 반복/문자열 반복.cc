#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i != t; i++) {
		int n;
		string s;
		cin >> n >> s;
		for (int j = 0; j != s.size(); j++) {
			for (int k = 0; k != n; k++) {
				printf("%c", s[j]);
			}
		}
		puts("");
	}
	return 0;
}