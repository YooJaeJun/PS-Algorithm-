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


void solution()
{
	int n, m;
	cin >> n >> m;
	vector<string> grid(n);
	forn(x, n)
	{
		string s;
		cin >> grid[x];
	}

	int siz = min(n, m);
	int ans = 1;
	forn(x, n)
	{
		forn(y, m)
		{
			for (int i = 1; i < siz; i++)
			{
				if (x + i >= n or y + i >= m) break;
				if (grid[x][y] == grid[x + i][y + i] and
					grid[x][y] == grid[x][y + i] and
					grid[x][y] == grid[x + i][y])
				{
					ans = max(ans, (i + 1) * (i + 1));
				}
			}
		}
	}
	cout << ans;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}