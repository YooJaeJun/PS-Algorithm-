#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vvvi = vector<vector<vector<int>>>;

struct coord
{
	int x, y, z, day;
};

vvvi grid;
int m, n, h;
int dx[6] = { -1,1,0,0,0,0 };
int dy[6] = { 0,0,-1,1,0,0 };
int dz[6] = { 0,0,0,0,-1,1 };
vector<coord> rotten;
vvvi visited;
int day = 1, beforeDay = 0;


void bfs()
{
	queue<coord> q;
	for (auto& elem : rotten)
	{
		q.push({ elem.x, elem.y, elem.z, 0 });
	}

	while (q.empty() == false)
	{
		int x = q.front().x;
		int y = q.front().y;
		int z = q.front().z;
		int curDay = q.front().day;
		q.pop();

		for (int i = 0; i < 6; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];
			if (nx < 0 || nx >= m || ny < 0 || ny >= n || nz < 0 || nz >= h) continue;
			if (visited[nz][ny][nx]) continue;
			if (grid[nz][ny][nx] == -1 || grid[nz][ny][nx] == 1) continue;	// 1이면 이미 q에 들어있을 것

			visited[nz][ny][nx] = true;
			grid[nz][ny][nx] = 1;
			q.push({ nx, ny, nz, curDay + 1 });
		}

		day = max(day, curDay);
	}
}

void solution() {
	cin >> m >> n >> h;
	grid = vvvi(h, vvi(n, vi(m)));
	visited = vvvi(h, vvi(n, vi(m)));

	bool isAllRotten = true;
	for (int z = 0; z < h; z++)
	{
		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < m; x++)
			{
				cin >> grid[z][y][x];
				if (grid[z][y][x] == 1)
				{
					rotten.push_back({ x,y,z,0 });
				}
				else if (grid[z][y][x] == 0)
				{
					isAllRotten = false;
				}
			}
		}
	}

	if (isAllRotten)
	{
		cout << 0;
		return;
	}

	bfs();

	for (int z = 0; z < h; z++)
	{
		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < m; x++)
			{
				if (grid[z][y][x] == 0)
				{
					cout << -1;
					return;
				}
			}
		}
	}

	cout << day;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) { solution(); }
	return 0;
}