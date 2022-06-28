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
	return tree[node] = init(start, mid, node * 2) * init(mid + 1, end, node * 2 + 1);
}

void update(int start, int end, int node, int idx, int val)
{
	if (idx < start || idx > end) return;
	tree[node] = val;
	if (start == end) return;
	int mid = (start + end) / 2;
	update(start, mid, node * 2, idx, val);
	update(mid + 1, end, node * 2 + 1, idx, val);
	tree[node] = tree[node * 2] * tree[node * 2 + 1];
}

int query(int start, int end, int node, int left, int right)
{
	if (left > end || right < start) return 1;
	if (left <= start and right >= end) return tree[node];
	int mid = (start + end) / 2;
	return query(start, mid, node * 2, left, right) * query(mid + 1, end, node * 2 + 1, left, right);
}


void solution()
{
	int k;
	while (cin >> n >> k)
	{
		tree = vi((n + 1) * 4);
		arr = vi(n + 1);

		forn1(i, n)
		{
			int num;
			cin >> num;
			arr[i] = (num < 0 ? -1 : num > 0 ? 1 : 0);
		}

		init(1, n, 1);
		
		string ans;

		while (k--)
		{
			char command;
			int i, j;
			cin >> command >> i >> j;
			if (command == 'C')
			{
				int x = i * j < 0 ? -1 : j > 0 ? 1 : 0;
				update(1, n, 1, i, x);
				arr[i] = x;
			}
			else
			{
				int x = query(1, n, 1, i, j);
				ans += (x < 0 ? '-' : x > 0 ? '+' : '0');
			}
		}
		cout << ans << '\n';
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