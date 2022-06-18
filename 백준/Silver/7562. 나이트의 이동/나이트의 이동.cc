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

int ans;
int n;
vvi grid;
vvi visited;

struct coord
{
	int x, y, depth;
};
int dx[8] = {-2,-1,1,2,2,1,-1,-2};
int dy[8] = {1,2,2,1,-1,-2,-2,-1};

void bfs(int sx, int sy, int ex, int ey)
{
	queue<coord> q;
	q.push({ sx, sy, 0 });

	while (false == q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int depth = q.front().depth;
		q.pop();
		if (x == ex and y == ey) ans = min(ans, depth);

		for (int i = 0; i < 8; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (visited[nx][ny]) continue;
			visited[nx][ny] = true;
			q.push({ nx, ny, depth + 1 });
		}
	}
}

void solution()
{
	ans = maxn;
	cin >> n;
	grid = vvi(n, vi(n));
	visited = vvi(n, vi(n));

	int sx, sy, ex, ey;
	cin >> sx >> sy >> ex >> ey;

	for (int i = 0; i < n; i++)
	{
		bfs(sx, sy, ex, ey);
	}
	cout << ans << '\n';
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}