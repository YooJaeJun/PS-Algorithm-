#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using db = deque<bool>;
using ddb = deque<deque<bool>>;
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define forn1(i, n) for (int i = 1; i <= (int)n; i++)
const int maxn = 1e9 + 7;
const double mod = 1e9 + 7;

struct coord
{
	int x, y;
};
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void solution()
{
	int n, l, r;
	cin >> n >> l >> r;
	vvi grid(n, vi(n));
	forn(x, n) forn(y, n) cin >> grid[x][y];

	ddb visited(n, db(n));
	bool flag = true;
	int ans = 0;
	vector<coord> cartel;
	int sum = 0;

	while (flag)
	{
		flag = false;
		for (auto& elem : visited)
		{
			fill(elem.begin(), elem.end(), false);
		}

		forn(x, n)
		{
			forn(y, n)
			{
				function<void(int, int)> bfs = [&](int sx, int sy)
				{
					queue<coord> q;
					q.push({ sx, sy });
					visited[sx][sy] = true;
					cartel.clear();
					cartel.push_back({ sx, sy });
					sum = grid[sx][sy];

					while (false == q.empty())
					{
						int x = q.front().x;
						int y = q.front().y;
						q.pop();
						
						for (int i = 0; i < 4; i++)
						{
							int nx = x + dx[i];
							int ny = y + dy[i];
							if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
							if (visited[nx][ny]) continue;
							if (abs(grid[x][y] - grid[nx][ny]) >= l and
								abs(grid[x][y] - grid[nx][ny]) <= r)
							{
								visited[nx][ny] = true;
								cartel.push_back({ nx, ny });
								q.push({ nx, ny });
								sum += grid[nx][ny];
								flag = true;
							}
						}
					}

					int siz = (int)cartel.size();
					for (auto& elem : cartel)
					{
						grid[elem.x][elem.y] = sum / siz;
					}
				};

				if (false == visited[x][y])
				{
					bfs(x, y);
				}
			}
		}
		if (false == flag) break;
		else ans++;
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