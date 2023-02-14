#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

vvi childs;
vi parent;
vi visited;
vvi ans;

void bt(int start, vector<int>& v) {
	if (childs[start].empty()) {
		ans.push_back(v);
		v.clear();
		return;
	}

	for (auto& elem : childs[start]) {
		if (visited[elem]) continue;
		visited[elem] = true;
		v.push_back(elem);
		bt(elem, v);
	}
}

void solution() {
	int n;
	cin >> n;

	childs = vvi(n + 1);
	parent = vi(n + 1);
	visited = vi(n + 1);
	int root = 0;

	for (int i = 1; i <= n; i++) {
		cin >> parent[i];
		if (i == parent[i]) {
			root = i;
		}
		childs[parent[i]].push_back(i);
	}

	visited[root] = true;
	vector<int> v;
	v.push_back(root);
	visited[root] = true;
	bt(root, v);

	if (n == 1) {
		cout << 1 << '\n' << root << '\n' << root << '\n';
		return;
	}

	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].size() << '\n';
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';

	v.clear();
	ans.clear();
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	for (int i = 0; i != t; i++) { solution(); }
	return 0;
}