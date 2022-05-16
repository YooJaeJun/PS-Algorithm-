#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

int n, m, k;
vi tree;
vi arr;
int mod = 1'000'000'007;

int init(int node, int start, int end) 
{
	if (start == end) return tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = (init(node * 2, start, mid) * init(node * 2 + 1, mid + 1, end)) % mod;
}

int mul(int node, int start, int end, int left, int right) 
{
	if (left > end || right < start) return 1;
	if (left <= start && right >= end) return tree[node];
	int mid = (start + end) / 2;
	return (mul(node * 2, start, mid, left, right) * mul(node * 2 + 1, mid + 1, end, left, right)) % mod;
}

int update(int node, int start, int end, int idx, double dif) 
{
	if (idx < start || idx > end) return tree[node];
	if (start == end) return tree[node] = dif;
	int mid = (start + end) / 2;
	return tree[node] = (update(node * 2, start, mid, idx, dif) * update(node * 2 + 1, mid + 1, end, idx, dif)) % mod;
}

void solution() {
	cin >> n >> m >> k;
	arr = vi(n);
	tree = vi(n * 4);
	for (int i = 0; i != n; i++) 
	{
		cin >> arr[i];
	}

	init(1, 0, n - 1);

	for (int i = 0; i != m + k; i++) 
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) 
			update(1, 0, n - 1, b - 1, c);
		else 
			cout << mul(1, 0, n - 1, b - 1, c - 1) << '\n';
	}
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) { solution(); }
	return 0;
}