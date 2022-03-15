#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int sum = i;
		string s = to_string(i);
		for (auto& ch : s) {
			sum += ch - '0';
		}
		if (sum == n) {
			cout << i;
			return 0;
		}
	}
	cout << 0;
	return 0;
}