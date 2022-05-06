#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

int n, m;
vi tree;
vi arr;

int init(int node, int start, int end) {
	if (start == end) return tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = min(init(node * 2, start, mid), init(node * 2 + 1, mid + 1, end));
}

int query(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return INT_MAX;
	if (left <= start && right >= end) return tree[node];
	int mid = (start + end) / 2;
	return min(query(node * 2, start, mid, left, right), query(node * 2 + 1, mid + 1, end, left, right));
}

void solution() {
	cin >> n >> m;
	tree = vi(n * 4);
	arr = vi(n);
	for (int i = 0; i != n; i++) {
		cin >> arr[i];
	}

	init(1, 0, n - 1);

	for (int i = 0; i != m; i++) {
		int left, right;
		cin >> left >> right;
		cout << query(1, 0, n - 1, left - 1, right - 1) << '\n';
	}
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) { solution(); }
	return 0;
}