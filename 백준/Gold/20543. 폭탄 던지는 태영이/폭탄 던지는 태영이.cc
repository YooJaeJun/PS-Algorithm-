#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<long long>> bombed(n, vector<long long>(n));
	for (int x = 0; x != n; x++) {
		for (int y = 0; y != n; y++) {
			scanf("%lld", &bombed[x][y]);
			bombed[x][y] *= -1;
		}
	}

	vector<vector<long long>> ans(n, vector<long long>(n));
	int r = m / 2;
	for (int i = r; i < n - r; i++) {
		for (int j = r; j < n - r; j++) {
			// 누적합 참고
			// ans[i][j] = bombed[i-r][j-r];
			// ans[i][j] -= bombed[i-r-1][j-r] - bombed[i-r][j-r-1] + bombed[i-r-1][j-r-1];
			// ans[i][j] += ans[i-m][j] + ans[i][j-m] - ans[i-m][j-m];
			ans[i][j] = bombed[i - r][j - r];
			if (i - r - 1 >= 0) {
				ans[i][j] -= bombed[i - r - 1][j - r];
			}
			if (j - r - 1 >= 0) {
				ans[i][j] -= bombed[i - r][j - r - 1];
			}
			if (i - r - 1 >= 0 && j - r - 1 >= 0) {
				ans[i][j] += bombed[i - r - 1][j - r - 1];
			}
			if (i - m >= 0) {
				ans[i][j] += ans[i - m][j];
			}
			if (j - m >= 0) {
				ans[i][j] += ans[i][j - m];
			}
			if (i - m >= 0 && j - m >= 0) {
				ans[i][j] -= ans[i - m][j - m];
			}
		}
	}
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			printf("%lld ", ans[x][y]);
		}
		printf("\n");
	}
	return 0;
}