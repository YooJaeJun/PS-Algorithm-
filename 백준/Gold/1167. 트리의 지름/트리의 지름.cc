#include <iostream>
#include <vector>
using namespace std;

vector<vector<pair<int, int>>> tree;
vector<int> visited;
int diameter = 0;
int secondStart;

void dfs(int start, int dist) {
	visited[start] = true;

	for (auto& elem : tree[start]) {
		if (visited[elem.first] == false) {
			dfs(elem.first, dist + elem.second);
		}
	}
	if (diameter < dist) {
		diameter = dist;
		secondStart = start;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int v;
	cin >> v;
	tree.resize(v + 1);
	visited.resize(v + 1);
	for (int i = 0; i != v; i++) {
		int num = 0;
		int n1, n2, dist;
		cin >> n1;
		while (1) {
			cin >> n2;
			if (n2 == -1) { break; }
			cin >> dist;
			tree[n1].push_back({ n2, dist });
			tree[n2].push_back({ n1, dist });
		}
	}

	// 트리의 지름 = 두 번 탐색
	fill(visited.begin(), visited.end(), false);
	dfs(1, 0);
	fill(visited.begin(), visited.end(), false);
	dfs(secondStart, 0);

	cout << diameter;

	return 0;
}