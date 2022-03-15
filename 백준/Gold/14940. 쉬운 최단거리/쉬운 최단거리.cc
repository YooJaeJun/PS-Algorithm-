#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int n, m;
int nodes[1001][1001];
int visited[1001][1001];
int ans[1001][1001];

void bfs(int x, int y) {
	queue<vector<int>> q;
	q.push({ x, y, 0 });
	visited[x][y] = true;
	ans[x][y] = (nodes[x][y] == 2) ? 0 : -1;

	while (false == q.empty()) {
		int bx = q.front()[0];
		int by = q.front()[1];
		int dist = q.front()[2];
		q.pop();
		for (int i = 0; i != 4; i++) {
			int nx = bx + dx[i];
			int ny = by + dy[i];
			if (nx >= 1 && nx <= n &&
				ny >= 1 && ny <= m &&
				visited[nx][ny] == false &&
				nodes[nx][ny] != 0) {
				
				visited[nx][ny] = true;
				q.push({ nx, ny, dist + 1 });
				ans[nx][ny] = ans[x][y] == -1 ? -1 : dist + 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	int startX = 0;
	int startY = 0;
	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= m; y++) {
			cin >> nodes[x][y];
			startX = nodes[x][y] == 2 ? x : startX;
			startY = nodes[x][y] == 2 ? y : startY;
		}
	}

	bfs(startX, startY);

	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= m; y++) {
			if (visited[x][y] == false &&
				nodes[x][y] != 0) {
				bfs(x, y);
			}
		}
	}

	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= m; y++) {
			cout << ans[x][y] << ' ';
		}
		cout << '\n';
	}

	return 0;
}