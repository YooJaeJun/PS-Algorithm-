#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;


int n, q;
vi tree, arr, lazy;

void init(int start, int end, int node)
{
	if (start == end)
	{
		tree[node] = arr[start];
		return;
	}
	int mid = (start + end) / 2;
	init(start, mid, node * 2);
	init(mid + 1, end, node * 2 + 1);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void updateLazy(int start, int end, int node)
{
	if (lazy[node] == 0) return;
	tree[node] = (end - start + 1) * lazy[node];
	if (start != end)
	{
		lazy[node * 2] = lazy[node];
		lazy[node * 2 + 1] = lazy[node];
	}
	lazy[node] = 0;
}

void updateRange(int start, int end, int node, int left, int right, int dif)
{
	updateLazy(start, end, node);
	if (left > end || right < start) return;

	if (left <= start && end <= right)
	{
		tree[node] = (end - start + 1) * dif;
		if (start != end)
		{
			lazy[node * 2] = dif;
			lazy[node * 2 + 1] = dif;
		}
		return;
	}
	int mid = (start + end) / 2;
	updateRange(start, mid, node * 2, left, right, dif);
	updateRange(mid + 1, end, node * 2 + 1, left, right, dif);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int sum(int start, int end, int node, int left, int right)
{
	updateLazy(start, end, node);
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

void solution()
{
	cin >> n >> q;
	arr = vi(n);
	tree = vi(n * 4);
	lazy = vi(n * 4);

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	init(0, n - 1, 1);

	for (int i = 0; i < q; ++i)
	{
		int a, b, c;
		cin >> a >> b;
		if (a == 1)
		{
			cin >> c;
			updateRange(0, n - 1, 1, b - 1, b - 1, c);
			cout << sum(0, n - 1, 1, 0, n - 1) << '\n';
		}
		else
		{
			updateRange(0, n - 1, 1, 0, n - 1, b);
			cout << sum(0, n - 1, 1, 0, n - 1) << '\n';
		}
	}
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}