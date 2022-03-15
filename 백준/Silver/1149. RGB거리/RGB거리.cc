#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int memo[1001][3];	// [3] == r,g,b
int cost[1001][3];

int checkMin(int a, int b) {
	return a < b ? a : b;
}

int dp(int cur, int i) {
	if (cur == 0) { return 0; }
	if (memo[cur][i] != 0) {
		return memo[cur][i];
	}

	switch (i)
	{
	case 0:
		memo[cur][i] += checkMin(dp(cur - 1, 1), dp(cur - 1, 2)) + cost[cur][0];
		break;
	case 1:
		memo[cur][i] += checkMin(dp(cur - 1, 0), dp(cur - 1, 2)) + cost[cur][1];
		break;
	case 2:
		memo[cur][i] += checkMin(dp(cur - 1, 0), dp(cur - 1, 1)) + cost[cur][2];
		break;
	}
	return memo[cur][i];
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d", &cost[i][0], &cost[i][1], &cost[i][2]);
	}
	int ans = checkMin(checkMin(dp(n, 0), dp(n, 1)), dp(n, 2));
	cout << ans;
	return 0;
}