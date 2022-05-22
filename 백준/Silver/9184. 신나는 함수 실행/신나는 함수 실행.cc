#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vvvi = vector<vector<vector<int>>>;
#define yes cout << "YES\n";
#define no cout << "NO\n";
const int maxn = 100'001;
const double mod = 1e9 + 7;

vvvi dp;

int w(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0) return 1;
	if (a > 20 || b > 20 || c > 20) return w(20, 20, 20);
	if (dp[a][b][c] != 0) return dp[a][b][c];
	if (a < b && b < c)
	{
		dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
		return dp[a][b][c];
	}
	dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	return dp[a][b][c];
}

void solution()
{
	int a, b, c;
	dp = vvvi(51, vvi(51, vi(51)));
	w(20, 20, 20);
	while (1)
	{
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) return;
		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n';
	}
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}