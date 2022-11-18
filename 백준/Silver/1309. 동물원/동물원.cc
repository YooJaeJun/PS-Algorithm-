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
	vvi dp(n + 1, vi(3));	// 배치x, 왼배, 오배
	dp[1][0] = dp[1][1] = dp[1][2] = 1;
	int mod = 9901;

	for (int i = 2; i <= n; i++)
	{
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % mod;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % mod;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
	}

	cout << (dp[n][0] + dp[n][1] + dp[n][2]) % mod;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solution();
	return 0;
}