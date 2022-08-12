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

vi v;

int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

void solution()
{
	int n;
	cin >> n;
	v.clear();
	v.resize(n);
	forn(i, n) cin >> v[i];

	int sum = 0;
	forn(i, n - 1)
		for (int j = i + 1; j < n; j++)
			sum += gcd(v[i], v[j]);

	cout << sum << '\n';
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solution();
	return 0;
}