#include <iostream>
#include <array>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	vector<int> v(n + 1);
	vector<int> dp(n + 1);

	for (int i = 1; i <= n; i++)
		cin >> v[i];

	int answer = dp[1] = v[1];

	for (int i = 2; i <= n; i++)
	{
		dp[i] = max(dp[i - 1] + v[i], v[i]);
		answer = max(answer, dp[i]);
	}

	cout << answer;

	return 0;
}