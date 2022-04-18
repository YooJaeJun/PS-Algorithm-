#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> nodes;
int m, n, k;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int area = 0;

void dfs(int x, int y) {
	nodes[x][y] = 1;
	area++;
	for (int i = 0; i != 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
		if (nodes[nx][ny]) continue;
		dfs(nx, ny);
	}
}

void solution() {
	cin >> m >> n >> k;
	nodes.resize(m);
	for (auto& elem : nodes) {
		elem.resize(n);
	}

	for (int i = 0; i != k; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = y1; i != y2; i++) {
			for (int j = x1; j != x2; j++) {
				nodes[i][j] = 1;
			}
		}
	}

	vector<int> areas;
	for (int i = 0; i != m; i++) {
		for (int j = 0; j != n; j++) {
			if (nodes[i][j] == 0) {
				dfs(i, j);
				areas.push_back(area);
				area = 0;
			}
		}
	}

	cout << areas.size() << '\n';
	sort(areas.begin(), areas.end());
	for (auto& elem : areas) {
		cout << elem << ' ';
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}