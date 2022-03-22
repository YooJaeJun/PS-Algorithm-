#include <iostream>
#include <vector>
using namespace std;

int nodes[501][501] = {0, };
int sums[501][501] = {0, };
bool memo[501][501] = {false, };

void solution() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> nodes[i][j];
		}
	}

	sums[1][1] = nodes[1][1];	// 첫 수
	int ans = sums[1][1];

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (memo[i][j]) { continue; }	// 메모이제이션

			memo[i][j] = true;

			if (j == 1) {	// 첫 열
				sums[i][j] += sums[i - 1][j] + nodes[i][j];
			}
			else if (j == i) { // 끝 열
				sums[i][j] += sums[i - 1][j - 1] + nodes[i][j];
			}
			else {	// 중간
				sums[i][j] += max(sums[i - 1][j - 1], sums[i - 1][j]) + nodes[i][j];
			}

			ans = max(ans, sums[i][j]);
		}
	}

	cout << ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}