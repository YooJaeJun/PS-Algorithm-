#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vvvi = vector<vector<vector<int>>>;
using db = deque<bool>;
using ddb = deque<deque<bool>>;
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define forn1(i, n) for (int i = 1; i <= (int)n; i++)
const int maxn = 1e9 + 7;
const int mod = 1000;

struct coord
{
	int x, y, breaking;
};

void solution()
{
	int n, m, k;
	cin >> n >> m >> k;
	vector<string> grid(n);
	forn(i, n)
	{
		string s;
		cin >> s;
		grid[i] = s;
	}

	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };
	int ans = -1;
	vvvi visited = vvvi(n, vvi(m, vi(k + 1)));
	visited[0][0][0] = 1;

	function<void()> bfs = [&]()
	{
		queue<coord> q;
		q.push({ 0, 0, 0 });

		while (q.empty() == false)
		{
			int x = q.front().x;
			int y = q.front().y;
			int breaking = q.front().breaking;
			q.pop();

			if (x == n - 1 and y == m - 1)
			{
				ans = visited[x][y][breaking];
				return;
			}

			forn(i, 4)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 or nx >= n or ny < 0 or ny >= m) continue;

				if (grid[nx][ny] == '1' and
					k >= breaking + 1 and
					visited[nx][ny][breaking + 1] == 0)
				{
					visited[nx][ny][breaking + 1] = visited[x][y][breaking] + 1;
					q.push({ nx, ny, breaking + 1 });
				}
				else if (grid[nx][ny] == '0' and
					visited[nx][ny][breaking] == 0)
				{
					visited[nx][ny][breaking] = visited[x][y][breaking] + 1;
					q.push({ nx, ny, breaking });
				}
			}
		}
	};
	bfs();

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