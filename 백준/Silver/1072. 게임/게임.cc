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
	int x, y;
	cin >> x >> y;
	int before = (double)(y * 100) / x;

	if (before >= 99)
	{
		cout << -1;
		return;
	}

	int after = before;
	int start = 0, end = 2'000'000'001, mid;
	while (start <= end)
	{
		mid = (start + end) / 2;
		after = (double)((y + mid) * 100) / (x + mid);
		if (after > before)
			end = mid - 1;
		else
			start = mid + 1;
	}
	cout << start;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solution();
	return 0;
}