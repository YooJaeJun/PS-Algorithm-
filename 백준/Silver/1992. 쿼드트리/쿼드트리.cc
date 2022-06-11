#include <bits/stdc++.h>
#include <unordered_map>
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


vector<string> grid;

void divConq(int x, int y, int siz)
{
	char pivot = grid[x][y];
    
	for (int i = x; i < x + siz; i++)
	{
		for (int j = y; j < y + siz; j++)
		{
			if (grid[i][j] != pivot)
			{
				cout << '(';
				if (siz >= 4)
				{
					divConq(x, y, siz / 2);
					divConq(x, y + siz / 2, siz / 2);
					divConq(x + siz / 2, y, siz / 2);
					divConq(x + siz / 2, y + siz / 2, siz / 2);
				}
				else
				{
					cout << grid[x][y] << grid[x][y + 1] << grid[x + 1][y] << grid[x + 1][y + 1];
				}
				cout << ')';
				return;
			}
		}
	}

	cout << pivot;
}

void solution()
{
	int n;
	cin >> n;
	grid = vector<string>(n);
	forn(i, n) cin >> grid[i];

	divConq(0, 0, n);
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}