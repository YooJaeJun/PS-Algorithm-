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
	while (1)
	{
		int n, more = 0, less = 11;
		bool ans = true, flag = true;
		string s;

		do {
			cin >> n;
			if (!n)
			{
				flag = false;
				break;
			}
			cin >> s;
			cin >> s;

			if (s[0] == 'h')
			{
				less = min(n, less);
			}
			else if (s[0] == 'l')
			{
				more = max(n, more);
			}
			else
			{
				if (n <= more || n >= less)
				{
					ans = false;
				}
				break;
			}
		} while (1);

		if (!flag) break;

		if (ans) cout << "Stan may be honest\n";
		else cout << "Stan is dishonest\n";
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