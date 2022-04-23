#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<vector<int>> nodes;
vector<int> deg;
int ans;

void topoSort() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 0) {
			q.push(i);
		}
	}

	vector<int> res;
	while (false == q.empty()) {
		int cur = q.front();
		q.pop();
		res.push_back(cur);

		int next = nodes[cur][0];
		if (--deg[next] == 0) {
			q.push(next);
		}
	}

	ans += res.size();
}

void solution() {
	cin >> n;
	nodes.clear();
	deg.clear();
	nodes.resize(n + 1);
	deg.resize(n + 1);

	for (int i = 1; i <= n; i++) {
		int node;
		cin >> node;
		nodes[i].push_back(node);
		deg[node]++;
	}
	
	ans = 0;
	topoSort();
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}