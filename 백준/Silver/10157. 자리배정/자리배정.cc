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
	int c, r;
	cin >> c >> r;
	int k;
	cin >> k;

	if (k > r * c)
	{
		cout << 0;
		return;
	}
	else if (k == r * c)
	{
		cout<< c / 2 + (c & 1) << ' ' << r / 2 + (r & 1);
		return;
	}

	int curR = r - 1, curC = c - 1;
	int y = 1, x = 1;
	int cur = 1;

	while (true)
	{
		if (k >= cur and k < cur + curR)
		{
			y += k - cur;
			break;
		}
		cur += curR;
		y += curR;

		if (curR != r - 1)
		{
			curR--;
		}

		if (k >= cur and k < cur + curC)
		{
			x += k - cur;
			break;
		}
		cur += curC;
		x += curC;

		curC--;

		if (k >= cur and k < cur + curR)
		{
			y -= k - cur;
			break;
		}
		cur += curR;
		y -= curR;

		curR--;

		if (k >= cur and k < cur + curC)
		{
			x -= k - cur;
			break;
		}
		cur += curC;
		x -= curC;

		curC--;
	}

	cout << x << ' ' << y;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solution();
	return 0;
}