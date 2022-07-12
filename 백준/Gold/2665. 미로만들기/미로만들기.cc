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
using dddb = deque<deque<deque<bool>>>;
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define forn1(i, n) for (int i = 1; i <= (int)n; i++)
const int maxn = 1e9 + 7;
const double mod = 1e9 + 7;

struct coord { int x, y, breaking; };

void solution()
{
	int n;
	cin >> n;
	vector<string> grid(n);
	forn(i, n) cin >> grid[i];
	vvi memo(n, vi(n, maxn));
	int ans = maxn;

	auto bfs = [&]()
	{
		int dx[4] = { 0,0,1,-1 };
		int dy[4] = { 1,-1,0,0 };

		queue<coord> q;
		q.push({ 0,0,0 });
		memo[0][0] = 0;

		while (q.empty() == false)
		{
			int x = q.front().x;
			int y = q.front().y;
			int breaking = q.front().breaking;
			q.pop();

			if (x == n - 1 and y == n - 1)
			{
				ans = min(ans, breaking);
				continue;
			}

			forn(i, 4)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				if (memo[nx][ny] != maxn)
				{
					if (memo[nx][ny] <= breaking) continue;
					memo[nx][ny] = breaking;
				}
				
				if (grid[nx][ny] == '0')
				{
					memo[nx][ny] = breaking + 1;
					q.push({ nx, ny, breaking + 1 });
				}
				else
				{
					memo[nx][ny] = breaking;
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
	while (t--) solution();
	return 0;
}