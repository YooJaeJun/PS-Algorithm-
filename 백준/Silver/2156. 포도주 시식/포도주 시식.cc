#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	vector<int> v(n), dp(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	dp[0] = v[0];
	int ans = dp[0];

	if (n > 1)
	{
		dp[1] = v[0] + v[1];
		ans = max(ans, dp[1]);
	}
	if (n > 2)
	{
		dp[2] = max(v[0] + v[2], v[0] + v[1]);
		dp[2] = max(dp[2], v[1] + v[2]);
		ans = max(ans, dp[2]);
	}

	for (int i=3; i<n; i++)
	{
		dp[i] = max(dp[i], dp[i - 1]);
		dp[i] = max(dp[i], dp[i - 2] + v[i]);
		dp[i] = max(dp[i], dp[i - 3] + v[i - 1] + v[i]);
		ans = max(ans, dp[i]);
	}

	cout << ans;

	return 0;
}