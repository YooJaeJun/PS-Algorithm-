#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solution() {
	string s;
	cin >> s;
	if (s == "0") {
		cout << 0;
		return;
	}
	string ans;
	for (int i = 0; i != s.size(); i++) {
		int num = s[i] - '0';
		string tmp;
		while (num > 1) {
			tmp = to_string(num % 2) + tmp;
			num /= 2;
		}
		if (num == 1) {
			tmp = to_string(num) + tmp;
		}
		if (i != 0) {
			while (tmp.size() < 3) {
				tmp = '0' + tmp;
			}
		}
		ans += tmp;
	}
	cout << ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}