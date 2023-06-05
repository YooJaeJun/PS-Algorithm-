#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	vector<vector<int>> v(n);

	for (int i=0; i<n; i++)
	{
		v[i].resize(i + 1);

		for (int j=0; j<i+1; j++)
			cin >> v[i][j];
	}

	vector<vector<int>> dp(n);
	dp[0].push_back(v[0][0]);
	int ans = dp[0][0];

	for (int i=1; i<n; i++)
	{
		dp[i].resize(i + 1);

		for (int j=0; j<i+1; j++)
		{
			if (j == 0)
				dp[i][j] = dp[i - 1][j] + v[i][j];
			else if (j == i)
				dp[i][j] = dp[i - 1][j - 1] + v[i][j];
			else
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + v[i][j];

			ans = max(ans, dp[i][j]);
		}
	}

	cout << ans;

	return 0;
}