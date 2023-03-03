#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> visited;
vector<vector<int>> nodes;

void initVisited() {
	for (auto& elem : visited) {
		elem = 0;
	}
}

void dfs(int v) {
	visited[v] = true;
	printf("%d ", v);
	for (auto& elem : nodes[v]) {
		if (visited[elem] == false) {
			dfs(elem);
		}
	}
}

void bfs(int v) {
	visited[v] = true;
	queue<int> q;
	q.push(v);
	while (false == q.empty()) {
		int w = q.front();
		q.pop();
		printf("%d ", w);
		for (auto& elem : nodes[w]) {
			if (visited[elem] == false) {
				visited[elem] = true;
				q.push(elem);
			}
		}
	}
	
}

int main() {
	int n, m, v;
	cin >> n >> m >> v;
	visited.resize(n + 1);
	nodes.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		nodes[n1].push_back(n2);
		nodes[n2].push_back(n1);
	}
	for (auto& elem : nodes) {
		sort(elem.begin(), elem.end());
	}
	dfs(v);
	initVisited();
	puts("");
	bfs(v);

	return 0;
}