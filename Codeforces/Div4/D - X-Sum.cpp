#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

int ans = 0, sum = 0;
vvi board;
int n, m;
int dx[4] = { -1,-1,1,1 };
int dy[4] = { -1,1,-1,1 };

void search(int x, int y) {
	sum += board[x][y];

	for (int i = 0; i != 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		while (nx >= 0 && nx < n && ny >= 0 && ny < m) {
			sum += board[nx][ny];
			nx += dx[i];
			ny += dy[i];
		}
	}
}

void solution() {
	cin >> n >> m;
	board = vvi(n, vi(m));
	for (int i = 0; i != n; i++) {
		for (int j = 0; j != m; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i != n; i++) {
		for (int j = 0; j != m; j++) {
			sum = 0;
			search(i, j);
			ans = max(ans, sum);
		}
	}
	cout << ans << '\n';
	ans = 0;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	for (int i = 0; i != t; i++) { solution(); }
	return 0;
}