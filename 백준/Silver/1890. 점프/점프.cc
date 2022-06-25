#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using db = deque<bool>;
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define forn1(i, n) for (int i = 1; i <= (int)n; i++)
const int maxn = 1e9 + 7;
const double mod = 1e9 + 7;

void solution()
{
	int n;
	cin >> n;
	vvi grid(n, vi(n));
	forn(i, n) forn(j, n) cin >> grid[i][j];
	vvi memo(n, vi(n));
	
	function<int(int, int)> dfs = [&](int x, int y) ->int {
		if (memo[x][y]) return memo[x][y];
		if (x == n - 1 and y == n - 1) return memo[x][y] = 1;
		if (grid[x][y] == 0) return 0;

		int nx = x + grid[x][y];
		if (nx < n) memo[x][y] += dfs(nx, y);
		int ny = y + grid[x][y];
		if (ny < n)  memo[x][y] += dfs(x, ny);
		return memo[x][y];
	};
	cout << dfs(0, 0);
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}