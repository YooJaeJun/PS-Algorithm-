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
vvi nodes, visited;
int dx[4] = { 0,0,1,-1 };
int dy[5] = { 1,-1,0,0 };
int maxSize = 0;

void dfs(int x, int y, int& siz)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if (nodes[nx][ny] == 0) continue;
		if (visited[nx][ny]) continue;
		visited[nx][ny] = true;
		siz++;
		dfs(nx, ny, siz);
	}
}


void solution()
{
	cin >> n >> m;
	nodes = vvi(n, vi(m));
	visited = vvi(n, vi(m));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> nodes[i][j];

	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (visited[i][j]) continue;
			if (nodes[i][j] == 0) continue;
			visited[i][j] = true;
			int siz = 1;
			dfs(i, j, siz);
			maxSize = max(maxSize, siz);
			cnt++;
		}
	}
	cout << cnt << '\n' << maxSize;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}