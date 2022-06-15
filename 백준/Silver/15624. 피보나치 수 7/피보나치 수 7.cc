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
const int maxn = 1e9 + 7;
const int mod = 1e9 + 7;


void solution()
{
	int n;
	cin >> n;
	vi dp(n + 1);
	dp[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		dp[i] = ((dp[i - 2] % mod) + (dp[i - 1] % mod)) % mod;
	}
	cout << dp[n];
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}