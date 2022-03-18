#include <iostream>
#include <vector>
using namespace std;

void solution() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int dp[1001] = {0, };
		dp[0] = 1;
		dp[1] = 1;
		dp[2] = 2;
		for (int i = 3; i <= n; i++) {
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		}
		cout << dp[n] << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}