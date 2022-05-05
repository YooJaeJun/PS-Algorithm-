#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

int n, cnt = 0;

void bt(string& s) {
	if (s.size() == n) {
		if (s[0] != '0' && stoi(s) % 3 == 0) {
			cnt++;
		}
		return;
	}
	for (int i = 0; i != 3; i++) {
		s += to_string(i);
		bt(s);
		s.pop_back();
	}
}

void solution() {
	cin >> n;
	string s;
	bt(s);
	cout << cnt;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) { solution(); }
	return 0;
}