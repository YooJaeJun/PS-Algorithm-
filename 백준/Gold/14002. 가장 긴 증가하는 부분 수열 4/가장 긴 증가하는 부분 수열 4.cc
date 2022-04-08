#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

void solution() {
	int n;
	cin >> n;
	vector<int> nodes(n);
	for (int i = 0; i != n; i++) {
		cin >> nodes[i];
	}

	vector<int> dp;
	vector<int> idxs;
	for (int i = 0; i != n; i++) {
		int idx = lower_bound(dp.begin(), dp.end(), nodes[i]) - dp.begin();
		if (idx >= dp.size()) {
			dp.push_back(nodes[i]);
		}
		else {
			dp[idx] = nodes[i];
		}
		idxs.emplace_back(idx + 1);
	}
	cout << dp.size() << '\n';

	int start = nodes.size() - 1;
	int idx = dp.size();
	stack<int> ans;

	for (int i = start; i >= 0; i--) {
		if (idx == 0) break;
		if (idxs[i] == idx) {
			ans.push(nodes[i]);
			idx--;
		}
	}
	while (ans.empty() == false) {
		cout << ans.top() << ' ';
		ans.pop();
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}