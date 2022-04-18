#include <iostream>
#include <vector>
using namespace std;

void solution() {
	int t;
	cin >> t;
	int dp[11] = {0, };
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i != 11; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
	while (t--) {
		int num;
		cin >> num;
		cout << dp[num] << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}
