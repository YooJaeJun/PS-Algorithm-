#include <bits/stdc++.h>
using namespace std;

void solution() {
	string s;
	cin >> s;
	sort(s.begin(), s.end(), greater<>());

	if (s.back() != '0' ||
		s.size() == 1) {
		cout << -1;
		return;
	}

	int sum = 0;
	for (int i = 0; i != s.size(); i++) {
		sum += s[i] - '0';
	}

	if (sum % 3 == 0) {
		cout << s;
	}
	else {
		cout << -1;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}