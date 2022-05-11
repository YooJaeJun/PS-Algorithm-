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
	vi arr(n), dp(n);
	for (int i = 0; i != n; i++) {
		cin >> arr[i];
	}

	dp[0] = arr[0];
	if (arr.size() > 1) dp[1] = arr[0] + arr[1];
	if (arr.size() > 2) dp[2] = max(arr[0], arr[1]) + arr[2];

	for (int i = 3; i < n; i++) {
		dp[i] = max(dp[i - 3] + arr[i - 1], dp[i - 2]) + arr[i];
	}

	cout << dp[n - 1];
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) { solution(); }
	return 0;
}