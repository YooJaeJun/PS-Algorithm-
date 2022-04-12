#include <iostream>
#include <vector>
using namespace std;

void solution() {
	int n;
	cin >> n;
	vector<int> dp(n + 1);
	vector<int> nodes(n + 1);
	nodes[n] = n;

	for (int i = 2; i <= n; i++) {

		dp[i] = dp[i - 1] + 1;
		nodes[i] = i - 1;

		if (i % 3 == 0 && dp[i] > dp[i / 3]) {
			dp[i] = dp[i / 3] + 1;
			nodes[i] = i / 3;
		}

		if (i % 2 == 0 && dp[i] > dp[i / 2]) {
			dp[i] = dp[i / 2] + 1;
			nodes[i] = i / 2;
		}
	}

	cout << dp[n] << '\n';

	cout << n << ' ';
	for (int i = n; i > 1;) {
		cout << nodes[i] << ' ';
		i = nodes[i];
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}