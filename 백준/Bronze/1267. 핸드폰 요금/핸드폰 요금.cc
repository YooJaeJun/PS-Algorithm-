#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;


void solution() {
	int n;
	cin >> n;
	int y = 0, m = 0;
	for (int i = 0; i != n; i++) {
		int time;
		cin >> time;
		y += (time / 30 + 1) * 10;
		m += (time / 60 + 1) * 15;
	}
	if (y < m) {
		cout << "Y" << ' ' << y;
	}
	else if (y > m) {
		cout << "M" << ' ' << m;
	}
	else {
		cout << "Y" << ' ' << "M" << ' ' << y;
	}
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) { solution(); }
	return 0;
}