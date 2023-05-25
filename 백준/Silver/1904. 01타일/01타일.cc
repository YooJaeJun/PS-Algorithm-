#include <iostream>
#include <vector>
using namespace  std;

int main()
{
	const int mod = 15746;
	int n;
	cin >> n;
	vector<int> dp(n + 1);

	dp[1] = 1;
	if (n >= 2)
		dp[2] = 2;

	for (int i = 3; i <= n; i++)
		dp[i] = (dp[i - 2] + dp[i - 1]) % mod;

	cout << dp[n];
}