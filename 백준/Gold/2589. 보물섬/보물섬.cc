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

struct coord { int r, c, depth; };

void solution()
{
	int n, m;
	cin >> n >> m;
	vector<string> grid(n);
	forn(i, n) cin >> grid[i];

	int ans = 0;
	ddb visited(n, db(m));

	forn(i, n)
	{
		forn(j, m)
		{
			if (grid[i][j] == 'L')
			{
				forn(k, n) fill(visited[k].begin(), visited[k].end(), false);

				function<void()> bfs = [&]()
				{
					queue<coord> q;
					q.push({ i, j, 0 });
					visited[i][j] = true;

					while (q.empty() == false)
					{
						int r = q.front().r;
						int c = q.front().c;
						int depth = q.front().depth;
						q.pop();
						ans = max(ans, depth);

						forn(i, 4)
						{
							int nr = r + dr[i];
							int nc = c + dc[i];
							if (!inGrid()) continue;
							if (grid[nr][nc] == 'W') continue;
							if (visited[nr][nc]) continue;
							visited[nr][nc] = true;
							q.push({ nr, nc, depth + 1 });
						}
					}
				};
				bfs();
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
	while (t--) solution();
	return 0;
}