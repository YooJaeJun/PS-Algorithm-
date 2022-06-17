#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using db = deque<bool>;
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define forn(i, n) for (int i = 0; i < (int)n; i++)
const int maxn = 1e9 + 7;
const double mod = 1e9 + 7;

int n, m;
vi arr;

void backTraking(vi & v)
{
	if (v.size() == m)
	{
		forn(i, m) cout << v[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++)
	{
		v.push_back(arr[i]);
		backTraking(v);
		v.pop_back();
	}
}

void solution()
{
	cin >> n >> m;
	arr.resize(n);
	forn(i, n) cin >> arr[i];
	sort(arr.begin(), arr.end());
	vi v;
	backTraking(v);
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}