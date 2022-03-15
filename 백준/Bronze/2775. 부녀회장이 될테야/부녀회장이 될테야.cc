#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int k, n;
		cin >> k >> n;
		vector<vector<int>> v(k + 1);
		for (int i = 0; i <= k; i++) {
			v[i].resize(n + 1);
		}
		for (int i = 1; i <= n; i++) {
			v[0][i] = i;
		}
		for (int i = 1; i <= k; i++) {
			for (int j = 1; j <= n; j++) {
				for (int k = 1; k <= j; k++) {
					v[i][j] += v[i - 1][k];
				}
			}
		}
		cout << v[k][n] << '\n';
	}

	return 0;
}