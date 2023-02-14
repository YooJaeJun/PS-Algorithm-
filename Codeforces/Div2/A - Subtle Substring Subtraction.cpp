#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

void solution() {
	string s;
	cin >> s;
	int sum = 0;
	if (s.size() % 2 == 0) {
		for (int i = 0; i != s.size(); i++) {
			sum += s[i] - 'a' + 1;
		}
		cout << "Alice" << ' ' << sum << '\n';
	}
	else {
		int start = s.front() < s.back() ? 1 : 0;
		int end = s.front() < s.back() ? s.size() - 1 : s.size() - 2;
		for (int i = start; i <= end; i++) {
			sum += s[i] - 'a' + 1;
		}
		sum -= start == 1 ? s[0] - 'a' + 1 : s.back() - 'a' + 1;

		if (sum < 0) cout << "Bob" << ' ' << -sum << '\n';
		else cout << "Alice" << ' ' << sum << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}