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


int m, n;	// 세로, 가로
vvi grid;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int ans = 0;
vvi memo;	// 0: 방문함, -1:방문한적없음, 1~:끝까지가서+1~

int dfs(int x, int y)
{
	if (memo[x][y] != -1)
		return memo[x][y];
	if (x == m - 1 && y == n - 1) 
		return 1;
	
	memo[x][y] = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
		if (grid[x][y] <= grid[nx][ny]) continue;

		memo[x][y] += dfs(nx, ny);
	}
	ans = max(ans, memo[x][y]);
	return memo[x][y];
}

void solution()
{
	cin >> m >> n;
	grid = vvi(m, vi(n));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> grid[i][j];

	memo = vvi(m, vi(n, -1));
	dfs(0, 0);

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