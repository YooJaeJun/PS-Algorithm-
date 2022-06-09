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
const double mod = 1e9 + 7;


void solution()
{
	int n;
	cin >> n;
	vi dp(n + 1);
	for (int i = 1; i <= n; i++) cin >> dp[i];
	for (int i = 1; i <= n; i++)
		for (int j = 2; i * j <= n; j++)
			dp[i * j] = max(dp[i * j], dp[i] * j);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j < i; j++)
			dp[i] = max(dp[i], dp[j] + dp[i - j]);

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