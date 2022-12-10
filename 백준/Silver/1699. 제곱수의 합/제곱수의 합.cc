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
	int n;
	cin >> n;
	vi dp(n + 1, 1e9);
	for (int i = 1; i * i <= n; i++)
	{
		dp[i * i] = 1;
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j * j <= n; j++)
		{
			if (i - j * j > 0)
			{
				dp[i] = min(dp[i], dp[i - j * j] + 1);
			}
			else break;
		}
	}

	cout << dp[n];
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solution();
	return 0;
}