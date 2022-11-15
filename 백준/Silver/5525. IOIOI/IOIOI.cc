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

	string o;
	cin >> o;
	
	vi dp(m + 1);
	bool prevI = false;
	int ans = 0;

	if (o[0] == 'I')
	{
		dp[0] = 1;
		prevI = true;
	}

	for (int i = 0; i < m; i++)
	{
		if (o[i] == 'I')
		{
			if (prevI == false)
			{
				dp[i] = dp[i - 1] + 1;
			}
			else
			{
				dp[i] = 1;
			}
			prevI = true;
		}
		else if (prevI)
		{
			dp[i] = dp[i - 1] + 1;
			prevI = false;
		}
		else
		{
			prevI = false;
		}

		if (dp[i] == 2 * n + 1)
		{
			ans++;
			dp[i] -= 2;
		}
	}

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