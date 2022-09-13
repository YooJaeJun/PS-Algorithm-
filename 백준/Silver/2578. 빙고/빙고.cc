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


void solution()
{
	const int n = 5;
	vvi bingo(n, vi(n));
	ddb clear(n, db(n));
	vector<pii> loc(25 + 1);

	forn(r, n)
	{
		forn(c, n)
		{
			cin >> bingo[r][c];
			loc[bingo[r][c]] = { r, c };
		}
	}

	int ans = 0;
	forn1(i, 25)
	{
		int num;
		cin >> num;
		clear[loc[num].first][loc[num].second] = true;

		int cnt = 0;
		if (0 == ans && i >= 12)	// 5+4+3
		{
			forn(r, n)
			{
				bool flag = true;
				forn(c, n)
				{
					if (false == clear[r][c])
					{
						flag = false;
						break;
					}
				}
				if (flag) cnt++;
			}

			forn(c, n)
			{
				bool flag = true;
				forn(r, n)
				{
					if (false == clear[r][c])
					{
						flag = false;
						break;
					}
				}
				if (flag) cnt++;
			}

			if (clear[0][0] && clear[1][1] && clear[2][2] && clear[3][3] && clear[4][4]) cnt++;
			if (clear[4][0] && clear[3][1] && clear[2][2] && clear[1][3] && clear[0][4]) cnt++;

			if (cnt >= 3)
			{
				ans = i;
			}
		}
	}
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