#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> nodes;
vector<vector<bool>> visited;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int n;

void dfs(int x, int y, int height) {
	visited[x][y] = true;
	for (int i = 0; i != 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 1 && nx <= n &&
			ny >= 1 && ny <= n &&
			visited[nx][ny] == false &&
			nodes[nx][ny] > height) {
			dfs(nx, ny, height);
		}
	}
}

void solution() {
	cin >> n;
	nodes.resize(n + 1);
	visited.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		nodes[i].resize(n + 1);
		visited[i].resize(n + 1);
	}

	int maxElem = -1;
	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= n; y++) {
			cin >> nodes[x][y];
			maxElem = max(maxElem, nodes[x][y]);
		}
	}

	int ans = 0;
	for (int i = 0; i < maxElem; i++) {
		int cnt = 0;
		for (auto& elem : visited) {
			fill(elem.begin(), elem.end(), false);
		}
		for (int x = 1; x <= n; x++) {
			for (int y = 1; y <= n; y++) {
				if (nodes[x][y] > i && visited[x][y] == false) {
					dfs(x, y, i);
					cnt++;
				}
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}