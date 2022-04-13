#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> nodes;
vector<vector<bool>> dp;

void checkPalindrom() {
	// i: 자릿수, j: 현재 시작 원소
	for (int i = 1; i <= dp.size() - 1; i++) {
		for (int j = 1; j <= dp.size() - i; j++) {
			// 1이면 무조건
			if (i == 1) {
				dp[i][j] = true;
			}
			// 2면 숫자 서로 같으면
			else if (i == 2 && 
				nodes[j] == nodes[j + 1]) {
				dp[i][j] = true;
			}
			// 시작 == 끝 && 시작+1, 끝-1 dp가 트루면
			else if (nodes[j] == nodes[j + i - 1] &&
				dp[i - 2][j + 1]) {
				dp[i][j] = true;
			}
			else {
				dp[i][j] = false;
			}
		}
	}
}

void solution() {
	int n;
	cin >> n;
	nodes.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> nodes[i];
	}

	dp.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		dp[i].resize(n + 1);
	}

	checkPalindrom();

	int m;
	cin >> m;
	for (int i = 1; i <= m; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		cout << dp[n2 - n1 + 1][n1] << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}