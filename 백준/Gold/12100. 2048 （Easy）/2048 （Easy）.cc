#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
#define yes cout << "YES\n";
#define no cout << "NO\n";
const int maxn = 100'001;
const double mod = 1e9 + 7;


int n;
int dx[4] = { 0,0,-1,1 };	// 좌우상하
int dy[4] = { -1,1,0,0 };
int ans = 0;

bool isValid(int x, int y) 
{
	return x >= 0 && x < n && y >= 0 && y < n;
}

void goBack(vvi& curBoard, int x, int y, int nx, int ny, int i)
{
	nx -= dx[i];
	ny -= dy[i];
	if (curBoard[nx][ny] == 0)
	{
		curBoard[nx][ny] = curBoard[x][y];
		curBoard[x][y] = 0;
	}
}

void dfs(vvi& board, int depth) 
{
	if (depth == 5) return;

	vvi curBoard(n, vi(n));

	for (int i = 0; i < 4; ++i)
	{
		for (int x = 0; x < n; ++x)
		{
			for (int y = 0; y < n; ++y)
			{
				curBoard[x][y] = board[x][y];
			}
		}

		vvi already(n, vi(n));	// 한 번 합쳐졌었나

		// 좌우상하 0123
		int startX = 0, startY = 0, endX = n, endY = n, coefX = 1, coefY = 1;
		if (i == 1) startX = 0, startY = n - 1, endX = n, endY = -1, coefX = 1, coefY = -1;
		else if (i == 3) startX = n - 1, startY = 0, endX = -1, endY = n, coefX = -1, coefY = 1;

		for (int x = startX; x != endX; x += coefX)
		{
			for (int y = startY; y != endY; y += coefY)
			{
				if (curBoard[x][y] == 0) continue;
				if (already[x][y]) continue;

				int nx = x + dx[i];
				int ny = y + dy[i];
				while (1)
				{
					if (isValid(nx, ny) == false)
					{
						goBack(curBoard, x, y, nx, ny, i);
						break;
					}
					if (curBoard[nx][ny] != 0)
					{
						if (already[nx][ny])
						{
							goBack(curBoard, x, y, nx, ny, i);
						}
						else if (curBoard[nx][ny] != curBoard[x][y])
						{
							goBack(curBoard, x, y, nx, ny, i);
						}
						else
						{
							curBoard[nx][ny] *= 2;
							curBoard[x][y] = 0;
							already[nx][ny] = true;
						}
						break;
					}
					nx += dx[i];
					ny += dy[i];
				}
			}
		}

		for (int x = 0; x < n; ++x)
		{
			for (int y = 0; y < n; ++y)
			{
				ans = max(ans, curBoard[x][y]);
			}
		}
		
		dfs(curBoard, depth + 1);
	}
}

void solution() {
	cin >> n;
	vvi board(n, vi(n));
	for (int i = 0; i != n; i++) 
	{
		for (int j = 0; j != n; j++) 
		{
			cin >> board[i][j];
		}
	}
	dfs(board, 0);
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