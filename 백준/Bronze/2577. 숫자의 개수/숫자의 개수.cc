#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	string s = to_string(a * b * c);
	int ans[10] = { 0, };
	for (int i = 0; i != 10; i++) {
		for (int j = 0; j != s.size(); j++) {
			if (s[j] - '0' == i) {
				ans[i]++;
			}
		}
	}
	for (int i = 0; i != 10; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}