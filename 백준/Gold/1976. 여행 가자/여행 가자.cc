#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

int n, m;
vi parent;
vvi nodes;

int getParent(int x) {
	if (x == parent[x]) return x;
	return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

bool findParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	return a == b;
}

void solution() {
	cin >> n >> m;
	parent = vi(n + 1);

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	nodes = vvi(n + 1, vi(n + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int num;
			cin >> num;
			nodes[i][j] = num;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (nodes[i][j]) {
				unionParent(i, j);
			}
		}
	}

	vi plan(m);
	for (int i = 0; i < m; i++) {
		cin >> plan[i];
	}
	for (int i = 1; i != m; i++) {
		if (parent[plan[i - 1]] != parent[plan[i]]) {
			cout << "NO" << '\n';
			return;
		}
	}
	cout << "YES" << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) { solution(); }
	return 0;
}