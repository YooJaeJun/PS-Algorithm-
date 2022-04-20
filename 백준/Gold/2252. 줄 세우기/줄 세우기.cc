#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<int> deg;
vector<vector<int>> nodes;

void topoSort() {
	vector<int> result;
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 0) {
			q.push(i);
		}
	}

	while (q.empty() == false) {
		int cur = q.front();
		q.pop();
		result.push_back(cur);
		for (auto& next : nodes[cur]) {
			if (--deg[next] == 0) {
				q.push(next);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << result[i] << ' ';
	}
}

void solution() {
	cin >> n >> m;
	nodes.resize(n + 1);
	deg.resize(n + 1);

	for (int i = 0; i != m; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		nodes[n1].push_back(n2);
		deg[n2]++;
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