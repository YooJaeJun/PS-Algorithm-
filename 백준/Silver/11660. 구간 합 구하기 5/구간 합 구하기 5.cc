#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> nodes;
vector<vector<int>> pSum;

void solution() {
	int n, m;
	cin >> n >> m;
	nodes.resize(n + 1);
	pSum.resize(n + 1);
	for (int i = 0; i <= n; i++) {
		nodes[i].resize(n + 1);
		pSum[i].resize(n + 1);
	}

	// 구간합
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> nodes[i][j];
			pSum[i][j] = nodes[i][j] + pSum[i][j - 1] + pSum[i - 1][j] - pSum[i - 1][j - 1];
		}
	}

	for (int i = 0; i != m; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int ans = pSum[x2][y2] - pSum[x2][y1 - 1] - pSum[x1 - 1][y2] + pSum[x1 - 1][y1 - 1];
		cout << ans << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}