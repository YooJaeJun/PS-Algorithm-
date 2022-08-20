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
	vvi grid(n, vi(m)), newGrid(n, vi(m)), visited(n, vi(m));
	forn(i, n) forn(j, m) 
	{
		cin >> grid[i][j]; 
		newGrid[i][j] = grid[i][j];
	}
	int ans = 0;

	while (1)
	{
		ans++;

		forn(r, n)
		{
			forn(c, m)
			{
				if (grid[r][c] == 0) continue;

				forn(i, 4)
				{
					int nr = r + dr[i];
					int nc = c + dc[i];
					if (!inGrid()) continue;
					if (grid[nr][nc] == 0) 
						newGrid[r][c] = newGrid[r][c] > 0 ? newGrid[r][c] - 1 : 0;
				}
			}
		}

		int check1 = 0;
		forn(r, n)
		{
			forn(c, m)
			{
				grid[r][c] = newGrid[r][c];
				if (grid[r][c] != 0) check1++;
			}
		}

		int check2 = 0;
		forn(i, n) fill(visited[i].begin(), visited[i].end(), false);
		function<void(int, int)> dfs = [&](int r, int c)
		{
			visited[r][c] = true;
			check2++;
			forn(i, 4)
			{
				int nr = r + dr[i];
				int nc = c + dc[i];
				if (!inGrid()) continue;
				if (grid[nr][nc] == 0) continue;
				if (visited[nr][nc]) continue;
				visited[nr][nc] = true;
				dfs(nr, nc);
			}
		};

		bool flag = true;
		for (int r = 0; r < n and flag; r++)
			for (int c = 0; c < m and flag; c++)
				if (grid[r][c]) { dfs(r, c); flag = false; }

		if (flag)
		{
			cout << 0;
			break;
		}
		else if (check1 != check2)
		{
			cout << ans;
			break;
		}
	}
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solution();
	return 0;
}