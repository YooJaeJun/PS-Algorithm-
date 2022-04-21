#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> nodes;
vector<int> deg;

void topoSort() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 0) {
			q.push(i);
		}
	}

	vector<int> res;
	while (q.empty() == false) {
		int cur = q.front();
		q.pop();
		res.push_back(cur);
		for (auto& next : nodes[cur]) {
			if (--deg[next] == 0) {
				q.push(next);
			}
		}
	}
	if (res.size() != n) {
		cout << 0;
		return;
	}
	for (auto& elem : res) {
		cout << elem << '\n';
	}
}

void solution() {
	cin >> n >> m;
	nodes.resize(n + 1);
	deg.resize(n + 1);

	for (int i = 1; i <= m; i++) {
		int order;
		cin >> order;

		int node1;
		cin >> node1;
		for (int j = 1; j < order; j++) {
			int node2;
			cin >> node2;
			nodes[node1].push_back(node2);
			deg[node2]++;
			node1 = node2;
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