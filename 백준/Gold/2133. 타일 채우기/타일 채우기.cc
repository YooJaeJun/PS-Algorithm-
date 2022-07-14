#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using db = deque<bool>;
using ddb = deque<deque<bool>>;
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define forn1(i, n) for (int i = 1; i <= (int)n; i++)
const int maxn = 1e9 + 7;
const double mod = 1e9 + 7;
#define gridCheck() if (nx < 0 or nx >= n or ny < 0 or ny >= n) continue;


void solution()
{
	int n;
	cin >> n;
	vi dp(n + 1);
	dp[2] = 3;
	dp[4] = 11;	// dp[2] * dp[2] + 2

	for (int i = 6; i <= n; i += 2)
	{
		dp[i] += dp[i - 2] * dp[2] + 2;

		for (int j = i - 4; j >= 2; j -= 2)
		{
			dp[i] += dp[j] * 2;
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