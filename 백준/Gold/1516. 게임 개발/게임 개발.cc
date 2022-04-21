#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<vector<int>> nodes;
vector<int> deg;
vector<int> times;

void topoSort() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 0) {
			q.push(i);
		}
	}

	vector<int> dp(n + 1);
	while (q.empty() == false) {
		int cur = q.front();
		q.pop();
		dp[cur] = max(dp[cur], times[cur]);

		for (auto& next : nodes[cur]) {
			dp[next] = max(dp[next], dp[cur] + times[next]);
			if (--deg[next] == 0) {
				q.push(next);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << dp[i] << '\n';
	}
}

void solution() {
	cin >> n;
	nodes.resize(n + 1);
	deg.resize(n + 1);
	times.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> times[i];
		while(1) {
			int node;
			cin >> node;
			if (node == -1) break;
			nodes[node].push_back(i);
			deg[i]++;
		}
	}
	topoSort();
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}