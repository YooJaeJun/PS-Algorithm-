#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using db = deque<bool>;
using ddb = deque<deque<bool>>;
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define forn1(i, n) for (int i = 1; i <= (int)n; i++)
#define inGrid() ((nr >= 0) and (nr < n) and (nc >= 0) and (nc < m))
int dr[4] = { 0,0,-1,1 };
int dc[4] = { -1,1,0,0 };	// 좌우상하

vvi grid;

int devideConquer(int r, int c, int size)
{
	if (size == 2)
	{
		vi can(4);
		can[0] = grid[r][c];
		can[1] = grid[r][c + 1];
		can[2] = grid[r + 1][c];
		can[3] = grid[r + 1][c + 1];
		sort(can.begin(), can.end());
		return can[1];
	}
	vi can2(4);
	can2[0] = devideConquer(r, c, size / 2);
	can2[1] = devideConquer(r, c + size / 2, size / 2);
	can2[2] = devideConquer(r + size / 2, c, size / 2);
	can2[3] = devideConquer(r + size / 2, c + size / 2, size / 2);
	sort(can2.begin(), can2.end());
	return can2[1];
}

void solution()
{
	int n;
	cin >> n;
	grid = vvi(n, vi(n));
	forn(r, n) forn(c, n) cin >> grid[r][c];
	if (n == 1) cout << grid[0][0];
	else cout << devideConquer(0, 0, n);
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solution();
	return 0;
}