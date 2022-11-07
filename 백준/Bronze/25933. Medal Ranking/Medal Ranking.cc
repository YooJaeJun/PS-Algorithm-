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
	int usa[3], russia[3];
	int sum[2] = { 0,0 };
	forn(i, 3)
	{
		cin >> usa[i];
		sum[0] += usa[i];
	}
	forn(i, 3)
	{
		cin >> russia[i];
		sum[1] += russia[i];
	}

	forn(i, 3) cout << usa[i] << ' ';
	forn(i, 3) cout << russia[i] << ' ';
	cout << '\n';

	bool isCount = false;
	if (sum[0] > sum[1]) isCount = true;

	bool isColor = false;
	forn(i, 3)
	{
		if (usa[i] > russia[i])
		{
			isColor = true;
			break;
		}
		else if (usa[i] < russia[i])
		{
			break;
		}
	}

	cout << (isCount && isColor ? "both" : isCount ? "count" : isColor ? "color" : "none") << "\n\n";
}

int32_t main()
{
	// ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solution();
	return 0;
}