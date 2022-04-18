#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> nodes;
int visited[101] = { false, };
int ans = 0;

void dfs(int start, int end, int depth) {
	visited[start] = true;
	if (start == end) {
		ans = depth;
		return;
	}
	for (auto& elem : nodes[start]) {
		if (visited[elem]) continue;
		dfs(elem, end, depth + 1);
	}
}

void solution() {
	int n, start, end, m;
	cin >> n >> start >> end >> m;
	nodes.resize(n + 1);

	for (int i = 0; i != m; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		nodes[n1].push_back(n2);
		nodes[n2].push_back(n1);
	}

	dfs(start, end, 0);
	if (ans == 0) cout << -1;
	else cout << ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}