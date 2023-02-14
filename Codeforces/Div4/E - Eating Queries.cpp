
#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

void solution() {
	int n, q;
	cin >> n >> q;
	vi cSum(n);
	for (int i = 0; i != n; i++) {
		cin >> cSum[i];
	}

	sort(cSum.begin(), cSum.end(), greater<int>());
	for (int i = 1; i != n; i++) {
		cSum[i] += cSum[i - 1];
	}

	for (int i = 0; i != q; i++) {
		int x;
		cin >> x;
		int sum = 0;
		int ans = 0;

		if (x > cSum.back()) cout << -1 << '\n';
		else {
			int idx = lower_bound(cSum.begin(), cSum.end(), x) - cSum.begin();
			cout << idx + 1 << '\n';
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	for (int i = 0; i != t; i++) { solution(); }
	return 0;
}
