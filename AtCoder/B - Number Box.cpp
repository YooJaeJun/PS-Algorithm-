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


void solution()
{
	int n;
	cin >> n;
	vvi grid(n, vi(n));
	forn(i, n)
	{
		string s;
		cin >> s;
		forn(j, s.size())
		{
			grid[i][j] = s[j] - '0';
		}
	}

	// 위부터 시계방향
	int dx[8] = {-1,-1,0,1,1,1,0,-1};
	int dy[8] = {0,1,1,1,0,-1,-1,-1};

	auto search = [&](int x, int y)
	{
		int res = 0;
		forn(i, 8)
		{
			int maxNum = grid[x][y];
			forn(j, n - 1)
			{
				int nx = (x + dx[i]) % n;
				int ny = (y + dy[i]) % n;
				nx = nx < 0 ? nx + n : nx;
				ny = ny < 0 ? ny + n : ny;
				maxNum = maxNum * 10 + grid[nx][ny];
				x = nx;
				y = ny;
			}
			res = max(res, maxNum);
		}
		return res;
	};
	int ans = 0;
	forn(i, n) forn(j, n) ans = max(ans, search(i, j));
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