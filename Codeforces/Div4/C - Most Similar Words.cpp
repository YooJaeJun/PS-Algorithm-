#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;


void solution() {
	int n, m;
	cin >> n >> m;
	vector<string> vs(n);
	for (int i = 0; i != n; i++) {
		cin >> vs[i];
	}
	int dif = INT_MAX;
	for (int i = 0; i != n; i++) {
		for (int j = 0; j != n; j++) {
			int sum = 0;
			if (i == j) continue;
			for (int k = 0; k != m; k++) {
				sum += abs((int)vs[i][k] - vs[j][k]);
			}
			dif = min(dif, sum);
		}
	}
	cout << dif << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	for (int i = 0; i != t; i++) { solution(); }
	return 0;
}