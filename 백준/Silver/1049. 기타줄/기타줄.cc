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
	int n, m;
	cin >> n >> m;
	vi pack(m), one(m);
	forn(i, m)
	{
		cin >> pack[i];
		cin >> one[i];
	}
	sort(pack.begin(), pack.end());
	sort(one.begin(), one.end());

	int sum = 0;
	sum += min(pack[0] * (n / 6) + one[0] * (n % 6),
		min(one[0] * n, 
			pack[0] * (n / 6 + 1)));
	cout << sum;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solution();
	return 0;
}