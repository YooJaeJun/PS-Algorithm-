#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

int n;
vi v;

void solution() {
	cin >> n;
	v = vi(n);
	for (int i = 0; i != n; i++) {
		cin >> v[i];
	}

	int cnt = 0;
	for (int i = 0; i != n - 1; i++) {
		if (v[i] >= v[i + 1]) {
			if (v[i] == 0 && v[i + 1] == 0) {
				cout << -1 << '\n';
				return;
			}
			v[i] /= 2;
			i = -1;
			cnt++;
		}
	}

	cout << cnt << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	for (int i = 0; i != t; i++) { solution(); }
	return 0;
}