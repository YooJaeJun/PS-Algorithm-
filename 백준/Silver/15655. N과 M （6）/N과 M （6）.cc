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
const int mod = 1e9 + 7;

int n, m;
vi arr;
set<vi> ans;

void backTraking(vi& v, int idx)
{
	if (v.size() == m)
	{
		ans.insert(v);
		return;
	}

	for (int i = idx; i < n; i++)
	{
		v.push_back(arr[i]);
		backTraking(v, i + 1);
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
	backTraking(v, 0);

	for (auto& elem : ans)
	{
		forn(i, m)	cout << elem[i] << ' ';
		cout << '\n';
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