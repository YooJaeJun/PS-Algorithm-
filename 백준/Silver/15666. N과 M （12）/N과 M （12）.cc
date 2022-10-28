#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using db = deque<bool>;
using ddb = deque<deque<bool>>;
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define forn1(i, n) for (int i = 1; i <= (int)n; i++)
#define inGrid() ((nr >= 0) and (nr < n) and (nc >= 0) and (nc < m))
int dr[4] = { 0,0,-1,1 };
int dc[4] = { -1,1,0,0 };	// 좌우상하


void solution()
{
	int n, m;
	cin >> n >> m;
	vi v(n);
	forn(i, n) cin >> v[i];
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	n = v.size();

	function<void(vi, int, int)> bt = [&](vi cur, int depth, int idx)
	{
		if (depth == m)
		{
			for (auto& elem : cur) cout << elem << ' ';
			cout << '\n';
			return;
		}

		for (int i = idx; i < n; i++)
		{
			cur.push_back(v[i]);
			bt(cur, depth + 1, i);
			cur.pop_back();
		}
	};
	vi cur;
	bt(cur, 0, 0);
	cout << '\n';
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solution();
	return 0;
}