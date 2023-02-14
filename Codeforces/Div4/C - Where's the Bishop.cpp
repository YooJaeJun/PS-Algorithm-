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


void solution()
{
	const int n = 8;
	vector<string> board(n);
	for (int i = 0; i < n; i++)
		cin >> board[i];

	int ansr = 0, ansc = 0;
	int andFlag = false, breakFlag = false;
	for (int i = 0; i < n; i++)
	{
		int c1 = -1, c2 = -1;
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == '#')
			{
				if (andFlag)
				{
					ansr = i + 1;
					ansc = j + 1;
					breakFlag = true;
					break;
				}
				else if (c1 == -1)
				{
					c1 = j;
				}
				else
				{
					c2 = j;

					if (c2 - c1 == 2)
					{
						andFlag = true;
						break;
					}
				}
			}
		}
		if (breakFlag) break;
	}
	cout << ansr << ' ' << ansc << '\n';
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}