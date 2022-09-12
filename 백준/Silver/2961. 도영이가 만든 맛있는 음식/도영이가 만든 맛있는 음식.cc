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
	struct Taste { int bitter, sour; };
	vector<Taste> taste(n);
	forn(i, n) cin >> taste[i].bitter >> taste[i].sour;

	int ans = INT_MAX;
	forn1(selectNum, n)
	{
		function<void(int, int, int, int, int)> backTracking = 
			[&](int selectNum, int depth, int idx, int bitterSum, int sourSum)
		{
			if (depth == selectNum)
			{
				ans = min(ans, abs(bitterSum - sourSum));
				return;
			}
			for (int i = idx; i < n; i++)
			{
				backTracking(selectNum, depth + 1, i + 1, bitterSum * taste[i].bitter, sourSum + taste[i].sour);
			}
		};
		backTracking(selectNum, 0, 0, 1, 0);
	}
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