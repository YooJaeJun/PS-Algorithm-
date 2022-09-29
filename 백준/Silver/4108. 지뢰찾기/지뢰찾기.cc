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
#define inGrid() ((nr >= 0) and (nr < r) and (nc >= 0) and (nc < c))
int dr[8] = { 0,0,-1,1,-1,1,-1,1 };
int dc[8] = { -1,1,0,0,-1,1,1,-1 };


void solution()
{
	while (1)
	{
		int r, c;
		cin >> r >> c;
		if (r == 0 and c == 0) return;
		
		vector<string> grid(r);
		forn(i, r) cin >> grid[i];

		forn(i, r)
		{
			forn(j, c)
			{
				if (grid[i][j] == '*')
				{
					cout << '*';
				}
				else
				{
					int sum = 0;
					forn(k, 8)
					{
						int nr = i + dr[k];
						int nc = j + dc[k];
						if (!inGrid()) continue;
						if (grid[nr][nc] == '*') sum++;
					}
					cout << sum;
				}
			}
			cout << '\n';
		}
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