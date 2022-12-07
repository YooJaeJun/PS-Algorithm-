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
	int inc = 1, incCur = 1;
	int dec = 1, decCur = 1;

	forn(i, n)
	{
		cin >> v[i];
		if (i == 0) continue;

		if (v[i - 1] <= v[i])
		{
			incCur++;
		}
		else
		{
			inc = max(inc, incCur);
			incCur = 1;
		}
			
		if (v[i - 1] >= v[i])
		{
			decCur++;
		}
		else
		{
			dec = max(dec, decCur);
			decCur = 1;
		}
	}
	
	inc = max(inc, incCur);
	dec = max(dec, decCur);

	cout << max(inc, dec);
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solution();
	return 0;
}