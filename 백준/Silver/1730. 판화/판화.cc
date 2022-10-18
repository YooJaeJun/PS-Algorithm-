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
#define inGrid() ((nr >= 0) and (nr < n) and (nc >= 0) and (nc < n))
int dr[4] = { 0,0,-1,1 };
int dc[4] = { -1,1,0,0 };	// 좌우상하
enum DirState
{
	left, right, up, down
};


void solution()
{
	int n;
	cin >> n;
	string command;
	cin >> command;

	vector<string> grid(n);
	ddb h(n, db(n));
	ddb w(n, db(n));
	int r = 0, c = 0;

	for (auto& ch : command)
	{
		int nr, nc;

		switch (ch)
		{
		case 'U':
			nr = r + dr[DirState::up];
			nc = c + dc[DirState::up];
			if (inGrid())
			{
				h[r][c] = true;
				h[nr][nc] = true;
				r = nr;
				c = nc;
			}
			break;
		case 'D':
			nr = r + dr[DirState::down];
			nc = c + dc[DirState::down];
			if (inGrid())
			{
				h[r][c] = true;
				h[nr][nc] = true;
				r = nr;
				c = nc;
			}
			break;
		case 'L':
			nr = r + dr[DirState::left];
			nc = c + dc[DirState::left];
			if (inGrid())
			{
				w[r][c] = true;
				w[nr][nc] = true;
				r = nr;
				c = nc;
			}
			break;
		case 'R':
			nr = r + dr[DirState::right];
			nc = c + dc[DirState::right];
			if (inGrid())
			{
				w[r][c] = true;
				w[nr][nc] = true;
				r = nr;
				c = nc;
			}
			break;
		}
	}

	forn(r, n)
	{
		forn(c, n)
		{
			if (h[r][c] and w[r][c])
			{
				grid[r] += '+';
			}
			else if (h[r][c])
			{
				grid[r] += '|';
			}
			else if (w[r][c])
			{
				grid[r] += '-';
			}
			else
			{
				grid[r] += '.';
			}

			cout << grid[r][c];
		}
		cout << '\n';
	}
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solution();
	return 0;
}