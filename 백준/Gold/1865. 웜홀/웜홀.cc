#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, w;
vector<vector<int>> nodes;
int ans;

void floyd() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				nodes[i][j] = min(nodes[i][j], nodes[i][k] + nodes[k][j]);
				if (i == j) {
					ans = min(ans, nodes[i][j]);
					if (ans < 0) return;
				}
			}
		}
	}
}

void solution() {
	ans = 1e9;
	cin >> n >> m >> w;

	nodes = vector<vector<int>>(n + 1, vector<int>(n + 1, 1e9));
	for (int i = 0; i != m; i++) {
		int s, e, t;
		cin >> s >> e >> t;
		nodes[s][e] = min(nodes[s][e], t);
		nodes[e][s] = min(nodes[e][s], t);
	}
	for (int i = 0; i != w; i++) {
		int s, e, t;
		cin >> s >> e >> t;
		nodes[s][e] = min(nodes[s][e], -t);
	}

	floyd();

	if (ans < 0) cout << "YES" << '\n';
	else cout << "NO" << '\n';
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}