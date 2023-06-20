#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	constexpr int inf = 1'000'000'000;

	vector<vector<int>> dp(n + 1, vector<int>(10));	// 자리수, 수

	for (int i = 1; i < 10; i++)
		dp[1][i] = 1;

	for (int i=2; i<=n; i++)
	{
		for (int j=0; j<10; j++)
		{
			if (j > 0 && j < 9)
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % inf;
			else if (j == 0)
				dp[i][j] = dp[i - 1][j + 1];
			else if (j == 9)
				dp[i][j] = dp[i - 1][j - 1];

			dp[i][j] %= inf;
		}
	}

	int ans = 0;

	for (int i = 0; i < 10; i++)
	{
		ans += dp[n][i];
		ans %= inf;
	}

	cout << ans;

	return 0;
}