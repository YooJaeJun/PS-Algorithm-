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
	vi v(n);
	int diff = 0, ratio = 0;
	bool state = 0;	// 등차, 등비
	forn(i, n)
	{
		cin >> v[i];
		if (i == 1) diff = v[1] - v[0];
		else if (i > 1)
		{
			if (diff == v[i] - v[i - 1]) state = 0;
			else
			{
				state = 1;
				ratio = v[i] / v[i - 1];
			}
		}
	}

	if (state == 0) cout << v[n - 1] + diff;
	else cout << v[n - 1] * ratio;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solution();
	return 0;
}