#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

int n, m;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
vvi nodes;
int ans = 0, siz = 0;

void dfs(int x, int y) {
	nodes[x][y] = 0;
	siz++;

	for (int i = 0; i != 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
		if (nodes[nx][ny] == 0) continue;
		dfs(nx, ny);
	}
}

void solution() {
	int k;
	cin >> n >> m >> k;
	nodes = vvi(n + 1, vi(m + 1));

	for (int i = 0; i != k; i++) {
		int x, y;
		cin >> x >> y;
		nodes[x][y] = 1;
	}

	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= m; y++) {
			if (nodes[x][y]) {
				dfs(x, y);
				ans = max(ans, siz);
				siz = 0;
			}
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