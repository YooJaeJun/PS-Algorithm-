#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<pair<int, int>>> tree;	//노드 - 연결노드, 거리
vector<int> visited;
int diameter = 0;

void dfs(int start, int dist) {
	visited[start] = true;
	for (auto& node : tree[start]) {
		if (node.second != 0 &&
			visited[node.first] == false) {
			dfs(node.first, dist + node.second);
		}
	}
	diameter = diameter < dist ? dist : diameter;
	if (tree[start].size() == 1) {
		return;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	tree.resize(n + 1);
	visited.resize(n + 1);

	for (int i = 0; i != n - 1; i++) {
		int n1, n2, dist;
		cin >> n1 >> n2 >> dist;
		tree[n1].push_back({ n2,dist });
		tree[n2].push_back({ n1,dist });
	}

	vector<int> diameters;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			visited[j] = false;
		}
		dfs(i, 0);
		diameters.push_back(diameter);
		diameter = 0;
	}
	cout << *max_element(diameters.begin(), diameters.end());

	return 0;
}