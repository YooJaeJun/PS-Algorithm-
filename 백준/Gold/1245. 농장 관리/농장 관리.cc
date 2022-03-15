#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> nodes;
vector<vector<bool>> visited;
int dx[8] = { 0,0,1,-1,1,1,-1,-1 };
int dy[8] = { 1,-1,0,0,1,-1,1,-1 };
bool isMountain = true;
int n, m;

void dfs(int x, int y) {
	visited[x][y] = true;
	for (int i = 0; i != 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 1 && nx <= n &&
			ny >= 1 && ny <= m) {

			if (nodes[nx][ny] > nodes[x][y]) {
				isMountain = false;
			}
			else if (visited[nx][ny] == false &&
				nodes[nx][ny] == nodes[x][y]) {

				dfs(nx, ny);
			}
		}
	}
}

void solution() {
	cin >> n >> m;
	nodes.resize(n + 1);
	visited.resize(n + 1);
	for (int i = 0; i <= n; i++) {
		nodes[i].resize(m + 1);
		visited[i].resize(m + 1);
	}
	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= m; y++) {
			cin >> nodes[x][y];
		}
	}

	int ans = 0;
	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= m; y++) {
			if (nodes[x][y] != 0 &&
				visited[x][y] == false) {

				dfs(x, y);
				if (isMountain) { 
					ans++; 
				}
				isMountain = true;
			}
		}
	}
	cout << ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}