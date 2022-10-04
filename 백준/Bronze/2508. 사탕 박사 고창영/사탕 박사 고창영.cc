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
	int r, c;
	cin >> r >> c;
	vector<string> box(r);
	forn(i, r) cin >> box[i];

	int ans = 0;

	forn(i, r)
	{
		forn(j, c)
		{
			if (box[i][j] == '>')
			{
				if (j + 2 < c && 
					box[i].substr(j, 3) == ">o<")
				{
					ans++;
				}
			}
			else if (box[i][j] == 'v')
			{
				if (i + 2 < r &&
					box[i + 1][j] == 'o' &&
					box[i + 2][j] == '^')
				{
					ans++;
				}
			}
		}
	}

	cout << ans << '\n';
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solution();
	return 0;
}