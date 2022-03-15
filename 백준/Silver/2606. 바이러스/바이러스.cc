#include <iostream>
#include <vector>
using namespace std;

vector<int> visited;
vector<vector<int>> nodes;
int cnt;

void dfs(int v) {
	visited[v] = true;
	cnt++;
	for (auto& elem : nodes[v]) {
		if (visited[elem] == false) {
			dfs(elem);
		}
	}
}

int main() {
	cnt = -1;
	int n, m;
	cin >> n >> m;
	visited.resize(n + 1);
	nodes.resize(n + 1);
	while (m--) {
		int n1, n2;
		cin >> n1 >> n2;
		nodes[n1].push_back(n2);
		nodes[n2].push_back(n1);
	}
	dfs(1);
	cout << cnt;
	return 0;
}