#include <iostream>
#include <vector>
using namespace std;

vector<vector<pair<int, int>>> tree;
vector<int> visited;
int ans = 0;

void dfs(int n1, int n2, int dist) {
	visited[n1] = true;
	for (auto& elem : tree[n1]) {
		if (elem.second != 0 &&
			visited[elem.first] == false) {
			
			if (elem.first == n2) {
				ans = dist + elem.second;
				return;
			}
			else {
				dfs(elem.first, n2, dist + elem.second);
			}
		}
	}

}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	tree.resize(n + 1);
	visited.resize(n + 1);
	for (int i = 0; i != n - 1; i++) {
		int n1, n2, dist;
		cin >> n1 >> n2 >> dist;
		tree[n1].push_back({ n2, dist });
		tree[n2].push_back({ n1, dist });
	}

	while (m--) {
		ans = 0;
		for (auto& elem : visited) {
			elem = false;
		}
		int n1, n2;
		cin >> n1 >> n2;
		dfs(n1, n2, 0);
		cout << ans << '\n';
	}

	return 0;
}