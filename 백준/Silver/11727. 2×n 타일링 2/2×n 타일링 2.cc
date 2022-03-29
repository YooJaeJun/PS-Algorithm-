#include <iostream>
#include <vector>
using namespace std;

void solution() {
	int n;
	cin >> n;
	vector<int> dp(n + 1, 0);
	dp[1] = 1;
	if (dp.size() > 1) { dp[2] = 3; }
	const int inf = 10007;
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 2]) % inf;
	}
	cout << dp[n];
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	//cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}