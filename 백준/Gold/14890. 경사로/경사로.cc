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


vvi grid, check;
int n, l;
int ans = 0;

void search1(int i)
{
	bool flag = true;

	forn(x, n)
	{
		if (x != n - 1 and grid[x][i] == grid[x + 1][i] and
			(x != 0 and grid[x][i] == grid[x - 1][i])) continue;

		else if (x != n - 1 and
			(grid[x][i] <= grid[x + 1][i] - 2 or
			grid[x][i] - 2 >= grid[x + 1][i]))
		{
			flag = false;
			break;
		}

		// 큰 거 중심으로 좌우 검사
		if (x != n - 1 and 
			grid[x][i] == grid[x + 1][i] + 1)
		{
			for (int j = x + 1; j <= x + l; j++)
			{
				if (j >= n or
					check[j][i] or
					grid[x + 1][i] != grid[j][i])
				{
					flag = false;
					break;
				}

				check[j][i] = true;
			}
		}

		if (x != 0 and 
			grid[x][i] == grid[x - 1][i] + 1)
		{
			for (int j = x - 1; j >= x - l; j--)
			{
				if (j < 0 or
					check[j][i] or
					grid[x - 1][i] != grid[j][i])
				{
					flag = false;
					break;
				}

				check[j][i] = true;
			}
		}

		if (false == flag) break;
	}

	if (flag) 
		ans++;
}


void search2(int i)
{
	bool flag = true;

	forn(y, n)
	{
		if (y != n - 1 and grid[i][y] == grid[i][y + 1] and
			(y != 0 and grid[i][y] == grid[i][y - 1])) continue;

		else if (y != n - 1 and 
			(grid[i][y] <= grid[i][y + 1] - 2 or
			grid[i][y] - 2 >= grid[i][y + 1]))
		{
			flag = false;
			break;
		}

		// 큰 거 중심으로 좌우 검사
		if (y != n - 1 and 
			grid[i][y] == grid[i][y + 1] + 1)
		{
			for (int j = y + 1; j <= y + l; j++)
			{
				if (j >= n or
					check[i][j] or
					grid[i][y + 1] != grid[i][j])
				{
					flag = false;
					break;
				}

				check[i][j] = true;
			}
		}
		if (y != 0 and 
			grid[i][y] == grid[i][y - 1] + 1)
		{
			for (int j = y - 1; j >= y - l; j--)
			{
				if (j < 0 or
					check[i][j] or
					grid[i][y - 1] != grid[i][j])
				{
					flag = false;
					break;
				}

				check[i][j] = true;
			}
		}

		if (false == flag) break;
	}

	if (flag) 
		ans++;
}

void solution()
{
	cin >> n >> l;
	grid = vvi(n, vi(n));
	forn(x, n) forn(y, n) cin >> grid[x][y];
	check = vvi(n, vi(n));

	forn(i, n)
	{
		search1(i);
		forn(idx, n) fill(check[idx].begin(), check[idx].end(), false);
		search2(i);
		forn(idx, n) fill(check[idx].begin(), check[idx].end(), false);
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