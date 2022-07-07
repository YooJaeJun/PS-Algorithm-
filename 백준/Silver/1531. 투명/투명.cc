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
const int mod = 1000;

void solution()
{
	int n, m;
	cin >> n >> m;
	vvi grid(101, vi(101));
	while (n--)
	{
		int left, bottom, right, top;
		cin >> left >> bottom >> right >> top;
		for (int i = bottom; i <= top; i++)
			for (int j = left; j <= right; j++)
				grid[i][j]++;
	}

	int cnt = 0;
	forn1(i, 100) forn1(j, 100) if (grid[i][j] > m) cnt++;
	cout << cnt;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}