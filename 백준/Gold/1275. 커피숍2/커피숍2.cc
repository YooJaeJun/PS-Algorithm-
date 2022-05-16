#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
#define int int64_t
#define yes cout << "YES\n";
#define no cout << "NO\n";
const int max1 = 1'000'001;

int arr[max1], tree[max1 * 4];

int init(int start, int end, int node)
{
	if (start == end) return tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

void update(int start, int end, int node, int idx, int dif)
{
	if (idx < start || idx > end) return;
	tree[node] += dif;
	if (start == end) return;
	int mid = (start + end) / 2;
	update(start, mid, node * 2, idx, dif);
	update(mid + 1, end, node * 2 + 1, idx, dif);
}

int sum(int start, int end, int node, int left, int right)
{
	if (left > end || right < start) return 0;
	if (left <= start && right >= end) return tree[node];
	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}


void solution()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	init(0, n - 1, 1);

	for (int i = 0; i < m; ++i)
	{
		int x, y, a, b;
		cin >> x >> y;
		if (x > y) swap(x, y);

		cout << sum(0, n - 1, 1, x - 1, y - 1) << '\n';
		  
		cin >> a >> b;
		int dif = b - arr[a - 1];
		update(0, n - 1, 1, a - 1, dif);
		arr[a - 1] = b;
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