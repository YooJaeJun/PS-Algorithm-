#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void solution() {
	int n;
	cin >> n;
	vector<int> v(n);
	vector<int> dp(n);

	for (int i = 0; i != n; i++) {
		cin >> v[i];
		dp[i] = 1;	// 1로 초기화시켜야 함
	}

	for (int i = 0; i != n; i++) {
		for (int j = 0; j != i; j++) {
			if (v[i] < v[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	cout << *max_element(dp.begin(), dp.end());
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}