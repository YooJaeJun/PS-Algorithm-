#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using db = deque<bool>;
using ddb = deque<deque<bool>>;
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define forn1(i, n) for (int i = 1; i <= (int)n; i++)
int dr[4] = { 0,0,-1,1 };
int dc[4] = { -1,1,0,0 };	// 좌우상하


void solution()
{
	int n;
	cin >> n;
	vvi grid(n, vi(n));
	forn(r, n) forn(c, n) cin >> grid[c][r];

	enum edir { w, h, d };
	int ans = 0;

	auto InGrid = [&](int x, int y)
	{
		return (x >= 0) and (x < n) and (y >= 0) and (y < n);
	};

	function<void(int, int, int)> dfs = [&](int x, int y, int dir)
	{
		if (x == n - 1 && y == n - 1)
		{
			ans++;
			return;
		}

		if (InGrid(x + 1, y + 1) and
			!grid[x + 1][y] and !grid[x][y + 1] and !grid[x + 1][y + 1])
		{
			dfs(x + 1, y + 1, d);
		}

		switch (dir)
		{
		case w:
			if (InGrid(x + 1, y) and
				!grid[x + 1][y])
			{
				dfs(x + 1, y, w);
			}
			break;
		case h:
			if (InGrid(x, y + 1) and
				!grid[x][y + 1])
			{
				dfs(x, y + 1, h);
			}
			break;
		case d:
			if (InGrid(x + 1, y) and
				!grid[x + 1][y])
			{
				dfs(x + 1, y, w);
			}
			if (InGrid(x, y + 1) and
				!grid[x][y + 1])
			{
				dfs(x, y + 1, h);
			}
			break;
		}
	};

	dfs(1, 0, w);

	cout << ans;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solution();
	return 0;
}