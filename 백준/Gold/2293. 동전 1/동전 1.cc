#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> coins(n);
	for (int i = 0; i != n; i++) {
		cin >> coins[i];
	}
	vector<int> dp(k + 1);
	dp[0] = 1;
	for (auto& coin : coins) {
		for (int j = coin; j <= k; j++) {
			dp[j] += dp[j - coin];
		}
	}
	cout << dp[k];


	return 0;
}