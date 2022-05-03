#include <bits/stdc++.h>
using namespace std;

vector<int> nodes;
vector<int> dp;

void solution() {
	int n;
	cin >> n;
	nodes = vector<int>(2 * n);
	dp = vector<int>(2 * n);
	for (int i = 0; i != 2 * n; i++) {
		cin >> nodes[i];
	}

	dp[0] = nodes[0];
	dp[n] = nodes[n];

	for (int i = 1; i != n; i++) {
		// 첫째줄
		if (i + n - 1 >= n) {
			dp[i] = max(dp[i], dp[i + n - 1] + nodes[i]);
		}
		if (i + n - 2 >= n) {
			dp[i] = max(dp[i], dp[i + n - 2] + nodes[i]);
		}

		// 둘째줄
		if (i - 2 >= 0) {
			dp[n + i] = max(dp[n + i], dp[i - 2] + nodes[n + i]);
		}
		if (i - 1 >= 0) {
			dp[n + i] = max(dp[n + i], dp[i - 1] + nodes[n + i]);
		}
	}

	cout << *max_element(dp.begin(), dp.end()) << '\n';
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}