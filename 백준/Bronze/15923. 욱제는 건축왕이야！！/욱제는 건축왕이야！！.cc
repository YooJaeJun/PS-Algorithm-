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
	int n;
	cin >> n;
	vector<pii> building(n);
	forn(i, n)
	{
		cin >> building[i].first >> building[i].second;
	}

	int ans = 0;
	for (int i = 1; i < n; i++)
	{
		ans += abs(building[i - 1].first - building[i].first) +
			abs(building[i - 1].second - building[i].second);
	}
	ans += abs(building[n - 1].first - building[0].first) +
		abs(building[n - 1].second - building[0].second);

	cout << ans;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solution();
	return 0;
}