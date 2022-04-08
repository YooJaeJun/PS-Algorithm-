#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int inf = -99999999;

void solution() {
	int n;
	cin >> n;
	vector<int> dp(n + 1, inf);
	vector<int> nodes(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> nodes[i];
		dp[i] = nodes[i];
	}

	int ans = inf;
	for (int i = 1; i <= n; i++) {
		dp[i] = max(dp[i], dp[i - 1] + nodes[i]);
		ans = max(ans, dp[i]);
	}

	cout << ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}