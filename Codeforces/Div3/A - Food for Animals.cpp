#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

void solution() {
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	x -= a;
	y -= b;
	if (x > 0) c -= x;
	if (y > 0) c -= y;
	if (c >= 0) cout << "YES" << '\n';
	else cout << "NO" << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	for (int i = 0; i != t; i++) { solution(); }
	return 0;
}