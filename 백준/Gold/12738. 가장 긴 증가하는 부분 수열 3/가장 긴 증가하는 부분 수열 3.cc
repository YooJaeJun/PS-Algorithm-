#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solution() {
	int n;
	cin >> n;
	vector<int> nodes(n);
	for (int i = 0; i != n; i++) {
		cin >> nodes[i];
	}

	vector<int> dp;
	for (int i = 0; i != n; i++) {
		int idx = lower_bound(dp.begin(), dp.end(), nodes[i]) - dp.begin();
		if (idx >= dp.size()) {
			dp.push_back(nodes[i]);
		}
		else {
			dp[idx] = nodes[i];
		}
	}
	cout << dp.size();
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}