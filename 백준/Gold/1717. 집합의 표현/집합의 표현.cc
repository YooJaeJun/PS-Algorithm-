#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

vi parent;

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
	int n, m;
	cin >> n >> m;
	parent = vi(n + 1);
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i != m; i++) {
		int question, a, b;
		cin >> question >> a >> b;
		if (question == 0) {
			unionParent(a, b);
		}
		else {
			if (findParent(a, b)) {
				cout << "YES" << '\n';
			}
			else {
				cout << "NO" << '\n';
			}
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) { solution(); }
	return 0;
}