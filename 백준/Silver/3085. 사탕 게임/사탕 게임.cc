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
	int n;
	cin >> n;
	vector<string> grid1(n);
	forn(i, n) cin >> grid1[i];
	vector<string> grid2(n);
	forn(i, n)
	{
		grid2[i].assign(n, ' ');
		forn(j, n)
		{
			grid2[i][j] = grid1[j][i];
		}
	}
	int ans = 0;

	auto Check = [&](vector<string>& grid)
	{
		int ret = 0, cur = 1;

		// 가로
		forn(i, n)
		{
			forn(j, n - 1)
			{
				if (grid[i][j] == grid[i][j + 1])
				{
					cur++;
				}
				else
				{
					ret = max(ret, cur);
					cur = 1;
				}
			}
			ret = max(ret, cur);
			cur = 1;
		}
		ret = max(ret, cur);
		ans = max(ans, ret);

		// 세로
		cur = 1;
		forn(j, n)
		{
			forn(i, n - 1)
			{
				if (grid[i][j] == grid[i + 1][j])
				{
					cur++;
				}
				else
				{
					ret = max(ret, cur);
					cur = 1;
				}
			}
			ret = max(ret, cur);
			cur = 1;
		}
		ret = max(ret, cur);
		ans = max(ans, ret);
	};

	auto Swap = [&](vector<string>& grid)
	{
		Check(grid);

		forn(i, n)
		{
			forn(j, n - 1)
			{
				if (grid[i][j] != grid[i][j + 1])
				{
					swap(grid[i][j], grid[i][j + 1]);
					Check(grid);
					swap(grid[i][j], grid[i][j + 1]);
				}
			}
		}
	};
	Swap(grid1);
	Swap(grid2);

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