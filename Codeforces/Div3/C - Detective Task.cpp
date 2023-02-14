#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;


void solution() {
	string s;
	cin >> s;
	s = " " + s;
	int zeroIdx = -1, oneIdx = -1;
	for (int i = 1; i != s.size(); i++) {
		if (s[i] == '1') {
			oneIdx = i;
		}
		if (s[i] == '0') {
			zeroIdx = i;
			if (oneIdx == -1) {
				cout << zeroIdx << '\n';
				return;
			}
			else {
				cout << zeroIdx - oneIdx + 1 << '\n';
				return;
			}
		}
	}
	if (oneIdx == -1) {
		cout << s.size() - 1 << '\n';
	}
	else {
		cout << s.size() - oneIdx << '\n';
	}
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	for (int i = 0; i != t; i++) { solution(); }
	return 0;
}