#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> nodes;
vector<vector<bool>> visited_0;
vector<vector<bool>> visited_1;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int n;
vector<int> ans = { 0,0 };	// 0이면 아닌, 1이면 색약

void dfs(int x, int y, int idx) {
	if (idx == 0) { visited_0[x][y] = true; }
	if (idx == 1) { visited_1[x][y] = true; }
	
	for (int i = 0; i != 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n &&
			ny >= 0 && ny < n) {

			if (idx == 1 && visited_1[nx][ny] == false) {
				if ((nodes[x][y] == 'R' && nodes[nx][ny] == 'G') ||
					(nodes[x][y] == 'G' && nodes[nx][ny] == 'R') ||
					nodes[x][y] == nodes[nx][ny]) {
					dfs(nx, ny, idx);
				}
			}
			else if (idx == 0 && visited_0[nx][ny] == false) {
				if (nodes[x][y] == nodes[nx][ny]) {
					dfs(nx, ny, idx);
				}
			}
		}
	}
}

void solution() {
	cin >> n;
	nodes.resize(n);
	visited_0.resize(n);
	visited_1.resize(n);
	for (int i = 0; i != nodes.size(); i++) {
		nodes[i].resize(n);
		visited_0[i].resize(n);
		visited_1[i].resize(n);
	}

	for (int i = 0; i != n; i++) {
		for (int j = 0; j != n; j++) {
			cin >> nodes[i][j];
		}
	}

	for (int i = 0; i != n; i++) {
		for (int j = 0; j != n; j++) {
			if (visited_0[i][j] == false) {
				dfs(i, j, 0);
				ans[0]++;
			}
			if (visited_1[i][j] == false) {
				dfs(i, j, 1);
				ans[1]++;
			}
		}
	}

	cout << ans[0] << ' ' << ans[1];
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}