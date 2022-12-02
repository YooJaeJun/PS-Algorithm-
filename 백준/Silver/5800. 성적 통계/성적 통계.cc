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
	int k;
	cin >> k;
	forn1(i, k)
	{
		int n;
		cin >> n;
		vi v(n);
		forn(i, n) cin >> v[i];
		sort(v.begin(), v.end());

		int gap = 0;
		for (int i = 1; i < n; i++)
		{
			gap = max(gap, v[i] - v[i - 1]);
		}
		
		cout << "Class " << i << '\n';
		cout << "Max " << v[v.size() - 1] << ", Min " << v[0] << ", Largest gap " << gap << '\n';
	}
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solution();
	return 0;
}