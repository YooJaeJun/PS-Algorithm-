#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;


void solution() {
	int n, m;
	cin >> n >> m;
	vi arr(n + 1), psum(n + 1);
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		sum += arr[i];
		psum[i] = sum;
	}
	for (int i = 0; i != m; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		cout << psum[n2] - psum[n1 - 1] << '\n';
	}
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) { solution(); }
	return 0;
}