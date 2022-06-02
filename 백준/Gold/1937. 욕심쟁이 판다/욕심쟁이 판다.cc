#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
#define yes cout << "YES\n";
#define no cout << "NO\n";
const int maxn = 100001;
const double mod = 1e9 + 7;


int n;
vvi grid, memo;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int ans = 0;

int dfs(int x, int y)
{
	if (memo[x][y] != -1)
		return memo[x][y];

	memo[x][y] = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		if (grid[nx][ny] <= grid[x][y]) continue;

		memo[x][y] = max(memo[x][y], 1 + dfs(nx, ny));
	}

	return memo[x][y];
}

void solution()
{
	cin >> n;
	grid = vvi(n, vi(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> grid[i][j];

	memo = vvi(n, vi(n, -1));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (memo[i][j] == -1)
				ans = max(ans, 1 + dfs(i, j));
	cout << ans;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}