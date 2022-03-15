#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	int cnt = 0, ans = 0;
	for (int i = 666; ; i++) {
		cnt = 0;
		int continuous = 0;
		string str = to_string(i);
		for (auto& ch : str) {
			if (ch == '6') {
				continuous++;
				cnt++;
			}
			else {
				continuous = 0;
			}
			if (cnt >= 3 && continuous >= 3) {
				ans++;
				break;
			}
		}
		if (ans == n) {
			cout << str;
			return 0;
		}
	}

	return 0;
}