#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solution() {
	int n;
	cin >> n;
	vector<int> nodes(n);
	for (int i = 0; i < n; i++) {
		cin >> nodes[i];
	}

	vector<int> dp(1);
	dp[0] = nodes[0];
	vector<int> idxsForBacktracing;

	for (int i = 0; i < n; i++) {
		int idx = lower_bound(dp.begin(), dp.end(), nodes[i]) - dp.begin();

		if (idx >= dp.size()) {
			dp.push_back(nodes[i]);
		}
		else {
			dp[idx] = nodes[i];
		}

		idxsForBacktracing.push_back(idx + 1);	// LIS 원소 추적용
	}
	cout << dp.size() << '\n';

	int insertedIdx = dp.size();
	int start = idxsForBacktracing.size() - 1;
	vector<int> ans;

	for (int i = start; i >= 0; i--) {
		if (insertedIdx == 0) break;
		if (idxsForBacktracing[i] == insertedIdx) {
			ans.push_back(nodes[i]);
			insertedIdx--;
		}
	}
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i] << ' ';
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}