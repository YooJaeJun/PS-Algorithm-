#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	string ans;
	if (s.size() == 1) {
		cout << 0 << endl;
		ans = (s[0] - '0') % 3 == 0 ? "YES" : "NO";
		cout << ans;
		return 0;
	}
	for (int i = 1; ; i++) {
		int sum = 0;
		for (const char& elem : s) {
			sum += elem - '0';
		}
		if (sum < 10) {
			cout << i << endl;
			ans = sum % 3 == 0 ? "YES" : "NO";
			cout << ans;
			break;
		}
		s = to_string(sum);
	}
	return 0;
}