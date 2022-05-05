#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

int n, m;
vvi nodes;
vvi nodesCopy;
vvi visited;

struct coord {
	int x, y;
};

void bfs(int x, int y) {
	int dx[4] = { 0,0,-1,1 };
	int dy[4] = { -1,1,0,0 };
	queue<coord> q;
	q.push({ x, y });

	while (q.empty() == false) {
		int cx = q.front().x;
		int cy = q.front().y;
		q.pop();

		for (int i = 0; i != 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
			if (visited[nx][ny]) continue;
			if (nodesCopy[nx][ny] == 1) continue;
			visited[nx][ny] = true;
			nodesCopy[nx][ny] = 2;
			q.push({ nx, ny });
		}
	}
}

void solution() {
	cin >> n >> m;
	nodes = vvi(n + 1, vi(m + 1));
	nodesCopy = vvi(n + 1, vi(m + 1));
	visited = vvi(n + 1, vi(m + 1));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> nodes[i][j];
			nodesCopy[i][j] = nodes[i][j];
		}
	}
	
	int ans = 0;

	// 첫 번째 벽
	for (int x1 = 1; x1 <= n; x1++) {
		for (int y1 = 1; y1 <= m; y1++) {
			if (nodes[x1][y1] == 1 || nodes[x1][y1] == 2) continue;

			nodes[x1][y1] = 1;

			// 두 번째 벽
			for (int x2 = 1; x2 <= n; x2++) {
				for (int y2 = 1; y2 <= m; y2++) {
					if ((x1 == x2 && y1 == y2) ||
						nodes[x2][y2] == 1 || nodes[x2][y2] == 2) continue;

					nodes[x2][y2] = 1;

					// 세 번째 벽
					for (int x3 = 1; x3 <= n; x3++) {
						for (int y3 = 1; y3 <= m; y3++) {
							if ((x1 == x3 && y1 == y3) ||
								(x2 == x3 && y2 == y3) ||
								nodes[x3][y3] == 1 || nodes[x3][y3] == 2) continue;

							nodes[x3][y3] = 1;

							// 초기화
							for (int i = 1; i <= n; i++) {
								fill(visited[i].begin(), visited[i].end(), false);
							}
							for (int i = 1; i <= n; i++) {
								for (int j = 1; j <= m; j++) {
									nodesCopy[i][j] = nodes[i][j];
								}
							}

							// 바이러스
							for (int i = 1; i <= n; i++) {
								for (int j = 1; j <= m; j++) {
									if (nodesCopy[i][j] == 0 || nodesCopy[i][j] == 1) continue;
									bfs(i, j);
								}
							}

							// 안전영역
							int cnt = 0;
							for (int i = 1; i <= n; i++) {
								for (int j = 1; j <= m; j++) {
									if (nodesCopy[i][j] == 1 || nodesCopy[i][j] == 2) continue;
									cnt++;
								}
							}
							ans = max(ans, cnt);

							// 초기화
							nodes[x3][y3] = 0;
						}
					}

					nodes[x2][y2] = 0;
				}
			}

			nodes[x1][y1] = 0;
		}
	}

	cout << ans;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) { solution(); }
	return 0;
}