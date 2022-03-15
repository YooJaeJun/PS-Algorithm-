#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main() {
	int a;
	string s;
	string ans;
	while(true) {
		ans = "no";
		cin >> a;
		if (a == 0) { break; }
		s = to_string(a);
		for (int i = 0; i != s.size() / 2 + 1; i++) {
			if (s[i] == s[s.size() - 1 - i]) {
				ans = "yes";
			}
			else {
				ans = "no";
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}