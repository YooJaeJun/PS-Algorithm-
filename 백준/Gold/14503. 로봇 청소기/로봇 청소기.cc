#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
#define yes cout << "YES\n";
#define no cout << "NO\n";
const int maxn = 1e9 + 7;
const double mod = 1e9 + 7;


int n, m;
int nodes[50][50];
int visited[50][50];
int ans = 0;

enum class edir
{
	up, right, down, left
};
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

struct robot
{
	int x, y, dir;
};

int rotate(int dir, int degree)
{
	if (degree == 90) return dir - 1 >= 0 ? dir - 1 : (int)edir::left;
	else if (degree == 180) return dir - 2 >= 0 ? dir - 2 : dir + 2;
}

void clean(const int x, const int y, int dir)
{
	int flag = false;
	if (visited[x][y] == false) ans++;
	visited[x][y] = true;

	for (int i = 0; i < 4; i++)
	{
		dir = rotate(dir, 90);

		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nodes[nx][ny] == 1) continue;
		if (visited[nx][ny]) continue;

		flag = true;
		clean(nx, ny, dir);
		return;
	}
	// 후진 시도
	if (flag == false)
	{
		dir = rotate(dir, 180);
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nodes[nx][ny] == 1) return;
		dir = rotate(dir, 180);
		clean(nx, ny, dir);
	}
}

void solution()
{
	cin >> n >> m;
	int x, y, dir;
	cin >> x >> y >> dir;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			cin >> nodes[i][j];

	clean(x, y, dir);

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