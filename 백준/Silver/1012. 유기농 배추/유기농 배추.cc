#include <iostream>
using namespace std;

const int dx[4] = { 0, -1, 0, 1 };
const int dy[4] = { -1, 0, 1, 0 };

int cabbage[50][50];
int n, m, cnt;

void dfs(int x, int y) {
	cabbage[x][y] = false;

	for (int i = 0; i != 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (0 <= nx && nx < m &&
			0 <= ny && ny < n &&
			cabbage[nx][ny]) {
			dfs(nx, ny);
		}
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int k;
		cin >> m >> n >> k;
		cnt = 0;
		while (k--) {
			int x, y;
			cin >> x >> y;
			cabbage[x][y] = 1;
		}
		for (int x = 0; x != m; x++) {
			for (int y = 0; y != n; y++) {
				if (cabbage[x][y]) {
					cnt++;
					dfs(x, y);
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}