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
#define forn1(i, n) for (int i = 1; i <= (int)n; i++)
const int maxn = 1e9 + 7;
const double mod = 1e9 + 7;


void solution()
{
	int d, h, m;
	cin >> d >> h >> m;
	m -= 11;
	if (m < 0)
	{
		m = 60 + m;
		h -= 1;
	}
	h -= 11;
	if (h < 0)
	{
		h = 24 + h;
		d -= 1;
	}
	d -= 11;
	if (d < 0) cout << -1;
	else cout << d * 60 * 24 + h * 60 + m;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}