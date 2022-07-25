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
#define checkInGrid() if (nx < 0 or nx >= n or ny < 0 or ny >= m) continue;


void solution()
{
	enum edir { right, top, left, bottom };
	int dr[4] = { 0,-1,0,1 };
	int dc[4] = { 1,0,-1,0 };

	int n;
	cin >> n;
	vvi grid(101, vi(101));
	while (n--)
	{
		int r, c, d, g;
		cin >> c >> r >> d >> g;	// x, y

		vi dirs;
		// 시작점
		grid[r][c] = 1;
		// 0세대
		r = r + dr[d];
		c = c + dc[d];
		grid[r][c] = 1;
		dirs.push_back(d);

		if (g < 1) continue;
		// 1세대
		r = r + dr[(d + 1) % 4];
		c = c + dc[(d + 1) % 4];
		grid[r][c] = 1;
		dirs.push_back((d + 1) % 4);

		// 2~ 세대
		int t = pow(2, g);
		int forCompare = 2, coef = 0, dirIdx = 0;
		for (int cur = 3; cur <= t; cur++)
		{
			coef = (cur - forCompare <= forCompare / 2) ? 2 : 0;	// 3 .. 5,6 .. 9,10,11,12 .. 캐치 위한 식

			dirIdx = (dirs[cur - forCompare - 1] + coef) % 4;
			r = r + dr[dirIdx];
			c = c + dc[dirIdx];
			grid[r][c] = 1;

			dirs.push_back(dirIdx);
			if (cur % forCompare == 0) forCompare *= 2;
		}
	}

	int ans = 0;
	for (int r = 0; r <= 99; r++)
		for (int c = 0; c <= 99; c++)
			if (grid[r][c] and grid[r][c + 1] and grid[r + 1][c] and grid[r + 1][c + 1])
				ans++;

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