#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> nodes;
vector<bool> visited;
int m;

void dfs(int start, int depth, vector<int>& v) {
	if (depth == m) {
		for (auto& elem : v) {
			cout << elem << ' ';
		}
		cout << '\n';
		return;
	}

	visited[start] = true;

	for (auto& elem : nodes[start]) {
		if (visited[elem] == false) {
			v.push_back(elem);
			dfs(elem, depth + 1, v);
			v.pop_back();
		}
	}

	visited[start] = false;
}

void solution() {
	int n;
	cin >> n >> m;
	nodes.resize(n + 1);
	visited.resize(n + 1);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				nodes[i].push_back(j);
			}
		}
	}
	for (int i = 1; i != nodes.size(); i++) {
		vector<int> v{i};
		fill(visited.begin(), visited.end(), false);
		dfs(i, 1, v);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}