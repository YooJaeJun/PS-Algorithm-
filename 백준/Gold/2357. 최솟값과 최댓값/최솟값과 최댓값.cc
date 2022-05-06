#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

int n, m;
vi arr;
vi treeMin;
vi treeMax;

int initMin(int node, int start, int end) {
	if (start == end) return treeMin[node] = arr[start];
	int mid = (start + end) / 2;
	return treeMin[node] = min(initMin(node * 2, start, mid), initMin(node * 2 + 1, mid + 1, end));
}

int initMax(int node, int start, int end) {
	if (start == end) return treeMax[node] = arr[start];
	int mid = (start + end) / 2;
	return treeMax[node] = max(initMax(node * 2, start, mid), initMax(node * 2 + 1, mid + 1, end));
}

int queryMin(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return INT_MAX;
	if (left <= start && right >= end) return treeMin[node];
	int mid = (start + end) / 2;
	return min(queryMin(node * 2, start, mid, left, right), queryMin(node * 2 + 1, mid + 1, end, left, right));
}

int queryMax(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && right >= end) return treeMax[node];
	int mid = (start + end) / 2;
	return max(queryMax(node * 2, start, mid, left, right), queryMax(node * 2 + 1, mid + 1, end, left, right));
}

void solution() {
	cin >> n >> m;
	arr = vi(n);
	treeMin = vi(n * 4);
	treeMax = vi(n * 4);
	
	for (int i = 0; i != n; i++) {
		cin >> arr[i];
	}

	initMin(1, 0, n - 1);
	initMax(1, 0, n - 1);

	for (int i = 0; i != m; i++) {
		int left, right;
		cin >> left >> right;
		cout << queryMin(1, 0, n - 1, left - 1, right - 1) << ' ' <<
			queryMax(1, 0, n - 1, left - 1, right - 1) << '\n';
	}
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) { solution(); }
	return 0;
}