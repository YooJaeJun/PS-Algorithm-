#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solution() {
	int n, k;
	cin >> n >> k;
	int coin[10] = {0,};
	for (int i = 0; i != n; i++) {
		cin >> coin[i];
	}
	
	int ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (coin[i] <= k) {
			ans += k / coin[i];
			k %= coin[i];
		}
	}
	cout << ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}