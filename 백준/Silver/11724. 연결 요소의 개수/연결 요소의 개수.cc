#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> nodes;
vector<bool> visited;

void dfs(int start) {
	visited[start] = true;
	for (auto& elem : nodes[start]) {
		if (visited[elem] == false) {
			visited[elem] = true;
			dfs(elem);
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	nodes.resize(n + 1);
	while (m--) {
		int u, v;
		scanf("%d %d", &u, &v);
		nodes[u].push_back(v);
		nodes[v].push_back(u);
	}
	visited.resize(n + 1);
	int count = 0;
	for (int i = 1; i <= n; i++) {
		if (visited[i] == false) {
			dfs(i);
			count++;
		}
	}
	cout << count;
	return 0;
}