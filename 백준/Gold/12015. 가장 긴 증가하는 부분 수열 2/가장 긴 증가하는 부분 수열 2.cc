#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solution() {
	int n;
	cin >> n;
	vector<int> nodes(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> nodes[i];
	}

	vector<int> dp(2);
	dp[1] = nodes[1];

	for (int i = 2; i <= n; i++) {
		int idx = lower_bound(dp.begin(), dp.end(), nodes[i]) - dp.begin();
		if (idx >= dp.size()) {
			dp.push_back(nodes[i]);
		}
		else {
			dp[idx] = nodes[i];
		}
	}
	cout << dp.size() - 1;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}