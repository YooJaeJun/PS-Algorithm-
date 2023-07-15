#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	vector<int> dp(n, 1);
	int ans = 1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (v[i] > v[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
				ans = max(ans, dp[i]);
			}
		}
	}

	cout << ans;
	return 0;
}