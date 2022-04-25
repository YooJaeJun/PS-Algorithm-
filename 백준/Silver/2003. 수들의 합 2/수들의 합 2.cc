#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solution() {
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (int i = 0; i != n; i++) {
		cin >> v[i];
	}

	int i = 0, j = 0, sum = 0, ans = 0;
	while (1) {

		if (sum == m) {
			ans++;
			if (j >= n) break;
			sum -= v[i++];
			sum += v[j++];
		}
		else if (sum > m) {
			sum -= v[i++];
		}
		else {
			if (j >= n) break;
			sum += v[j++];
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