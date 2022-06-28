#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using db = deque<bool>;
using ddb = deque<deque<bool>>;
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define forn1(i, n) for (int i = 1; i <= (int)n; i++)
const int maxn = 1e9 + 7;
const double mod = 1e9 + 7;

int n;
vi tree, arr;

int init(int start, int end, int node)
{
	if (start == end) return tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = min(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
}

int update(int start, int end, int node, int idx, int value)
{
	if (idx < start || idx > end) return tree[node];
	tree[node] = value;
	if (start == end) return tree[node];
	int mid = (start + end) / 2;
	return tree[node] = min(update(start, mid, node * 2, idx, value), update(mid + 1, end, node * 2 + 1, idx, value));
}

int queryMin(int start, int end, int node, int left, int right)
{
	if (left > end || right < start) return INT_MAX;
	if (left <= start and right >= end) return tree[node];
	int mid = (start + end) / 2;
	return min(queryMin(start, mid, node * 2, left, right), queryMin(mid + 1, end, node * 2 + 1, left, right));
}

void solution()
{
	cin >> n;
	tree = vi(n * 4);
	arr = vi(n);

	forn(i, n) cin >> arr[i];

	init(0, n - 1, 1);

	int m;
	cin >> m;
	while(m--)
	{
		int command, i, j;
		cin >> command >> i >> j;
		if (command == 1)
		{
			update(0, n - 1, 1, i - 1, j);
			arr[i - 1] = j;
		}
		else cout << queryMin(0, n - 1, 1, i - 1, j - 1) << '\n';
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