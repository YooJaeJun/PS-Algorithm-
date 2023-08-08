#include <bits/stdc++.h>
using namespace std;

void solution()
{
	int n, m;
	cin >> n >> m;
	vector<int> day(m + 1), page(m + 1);
	vector<vector<int>> dp(m + 1, vector<int>(n + 1));

	for (int i = 1; i <= m; i++)
		cin >> day[i] >> page[i];

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (j - day[i] >= 0)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - day[i]] + page[i]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[m][n];
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}