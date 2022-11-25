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
#define inGrid() ((nr >= 0) and (nr < n) and (nc >= 0) and (nc < m))
int dr[4] = { 0,0,-1,1 };
int dc[4] = { -1,1,0,0 };	// 좌우상하


void solution()
{
	int n, m;
	cin >> n >> m;
	vvi grid(n, vi(m));
	vvi dp(n, vi(m));

	forn(i, n)
	{
		forn(j, m)
		{
			cin >> grid[i][j];
			if (i == 0 and j == 0) dp[0][0] = grid[0][0];
			if (i > 0) dp[i][j] = max(dp[i][j], grid[i][j] + dp[i - 1][j]);
			if (j > 0) dp[i][j] = max(dp[i][j], grid[i][j] + dp[i][j - 1]);
		}
	}

	cout << dp[n - 1][m - 1];
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solution();
	return 0;
}