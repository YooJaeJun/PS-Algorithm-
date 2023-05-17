#include <iostream>
#include <array>
#include <vector>

using namespace std;

int dp[21][21][21] = {0,};

int DP(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	if (a > 20 || b > 20 || c > 20)
		return dp[20][20][20];
	if (dp[a][b][c])
		return dp[a][b][c];
	if (a < b && b < c)
		return dp[a][b][c] = DP(a, b, c - 1) + DP(a, b - 1, c - 1) - DP(a, b - 1, c);
	return dp[a][b][c] = DP(a - 1, b, c) + DP(a - 1, b - 1, c) + DP(a - 1, b, c - 1) - DP(a - 1, b - 1, c - 1);
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	DP(20, 20, 20);

	while (true)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			return 0;

		int maxn = max(a, max(b, c));
		int answer = DP(a, b, c);
		cout << "w(" << a << ", " << b << ", " << c << ") = " << answer << '\n';
	}

	return 0;
}