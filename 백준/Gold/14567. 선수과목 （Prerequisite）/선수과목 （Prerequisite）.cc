#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> nodes;
vector<int> deg;

void topoSort() {
	queue<pair<int, int>> q;
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 0) {
			q.push({ i, 1 });
		}
	}

	vector<int> idxs(n);
	while (q.empty() == false) {
		int cur = q.front().first;
		int idx = q.front().second;
		q.pop();
		idxs[cur - 1] = idx;

		for (auto& next : nodes[cur]) {
			if (--deg[next] == 0) {
				q.push({ next, idx + 1 });
			}
		}
	}

	for (auto& elem : idxs) {
		cout << elem << ' ';
	}
}

void solution() {
	cin >> n >> m;
	nodes.resize(n + 1);
	deg.resize(n + 1);

	for (int i = 1; i <= m; i++) {
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