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
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	function<int(int, int)> gcd = [&](int n1, int n2)
	{
		if (n2 == 0) return n1;
		return gcd(n2, n1 % n2);
	};
	auto lcm = [&](int n1, int n2)
	{
		return n1 * n2 / gcd(n1, n2);
	};
	int denom = lcm(b, d);

	a *= denom / b;
	c *= denom / d;
	int numer = a + c;
	int minn = min(numer, denom);

	while (1)
	{
		int g = gcd(numer, denom);
		if (g == 1) break;
		numer /= g;
		denom /= g;
	}
	cout << numer << ' ' << denom;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solution();
	return 0;
}