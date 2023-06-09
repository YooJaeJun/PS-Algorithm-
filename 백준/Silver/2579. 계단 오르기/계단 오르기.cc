#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	vector<int> dp(n);
	dp[0] = v[0];

	if (n > 0)
		dp[1] = v[0] + v[1];
	if (n > 1)
		dp[2] = max(v[0], v[1]) + v[2];

	for (int i=3; i<n; i++)
		dp[i] = max(dp[i - 2], dp[i - 3] + v[i - 1]) + v[i];

	cout << dp[n - 1];

	return 0;
}
