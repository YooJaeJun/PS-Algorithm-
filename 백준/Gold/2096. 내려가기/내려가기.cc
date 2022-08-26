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
	vvi v(2, vi(3));
	cin >> v[0][0] >> v[0][1] >> v[0][2];
	vvi dpMax(2, vi(3)), dpMin(2, vi(3));
	dpMax[0][0] = dpMin[0][0] = v[0][0];
	dpMax[0][1] = dpMin[0][1] = v[0][1];
	dpMax[0][2] = dpMin[0][2] = v[0][2];

	forn1(i, n - 1)
	{
		cin >> v[1][0] >> v[1][1] >> v[1][2];

		dpMax[1][0] = max(dpMax[0][0], dpMax[0][1]) + v[1][0];
		dpMax[1][1] = max(dpMax[0][0], max(dpMax[0][1], dpMax[0][2])) + v[1][1];
		dpMax[1][2] = max(dpMax[0][1], dpMax[0][2]) + v[1][2];
		dpMax[0][0] = dpMax[1][0];
		dpMax[0][1] = dpMax[1][1];
		dpMax[0][2] = dpMax[1][2];

		dpMin[1][0] = min(dpMin[0][0], dpMin[0][1]) + v[1][0];
		dpMin[1][1] = min(dpMin[0][0], min(dpMin[0][1], dpMin[0][2])) + v[1][1];
		dpMin[1][2] = min(dpMin[0][1], dpMin[0][2]) + v[1][2];
		dpMin[0][0] = dpMin[1][0];
		dpMin[0][1] = dpMin[1][1];
		dpMin[0][2] = dpMin[1][2];

		v[0][0] = v[1][0];
		v[0][1] = v[1][1];
		v[0][2] = v[1][2];
	}

	int maxn = max(dpMax[0][0], max(dpMax[0][1], dpMax[0][2]));
	int minn = min(dpMin[0][0], min(dpMin[0][1], dpMin[0][2]));

	cout << maxn << ' ' << minn;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solution();
	return 0;
}