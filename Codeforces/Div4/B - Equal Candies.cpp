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
	vi v(n);
	int minNum = INT_MAX;
	for (int i = 0; i != n; i++) {
		cin >> v[i];
		minNum = min(minNum, v[i]);
	}
	int ans = 0;
	for (auto& elem : v) {
		ans += elem - minNum;
	}
	cout << ans << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	for (int i = 0; i != t; i++) { solution(); }
	return 0;
}