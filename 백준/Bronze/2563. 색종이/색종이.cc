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
	bool grid[101][101] = { false, };
	int n;
	cin >> n;
	forn(i, n)
	{
		int n1, n2;
		cin >> n1 >> n2;
		for (int i = n1; i < n1 + 10; i++)
			for (int j = n2; j < n2 + 10; j++)
				grid[i][j] = true;
	}

	int cnt = 0;
	for (int i = 1; i <= 100; i++)
		for (int j = 1; j <= 100; j++)
			if (grid[i][j])
				cnt++;
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