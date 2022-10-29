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
int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };	// 동서남북


void solution()
{
	int n;
	cin >> n;
	vector<double> dirPercent(4);
	cin >> dirPercent[0] >> dirPercent[1] >> dirPercent[2] >> dirPercent[3];
	for (auto& elem : dirPercent) elem /= 100;

	double ans = 0.0f;
	map<pair<int, int>, bool> visited;

	function<void(int, int, int, double)> dfs = [&](int r, int c, int n, double percent)
	{
		if (n == 0)
		{
			ans += percent;
			return;
		}

		for (int i = 0; i < 4; i++)
		{
			if (dirPercent[i] == 0) continue;
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (visited[{nr, nc}]) continue;
			visited[{nr, nc}] = true;
			dfs(nr, nc, n - 1, percent * dirPercent[i]);
			visited[{nr, nc}] = false;
		}
	};
	visited[{0, 0}] = true;
	dfs(0, 0, n, 1.0);

	cout << fixed;
	cout.precision(9);
	cout << ans;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solution();
	return 0;
}