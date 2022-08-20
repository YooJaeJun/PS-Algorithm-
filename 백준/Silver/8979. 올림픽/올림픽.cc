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


struct medal
{
	int idx, gold, silver, copper;
	bool operator<(const medal& other) const
	{
		if (gold == other.gold)
			if (silver == other.silver)
				return copper > other.copper;
			else return silver > other.silver;
		else return gold > other.gold;
	}
	bool operator==(const medal& other) const
	{
		return gold == other.gold and silver == other.silver and copper == other.copper;
	}
};

void solution()
{
	int n, k;
	cin >> n >> k;
	vector<medal> v(n);
	forn(i, n) cin >> v[i].idx >> v[i].gold >> v[i].silver >> v[i].copper;
	sort(v.begin(), v.end());
	forn(i, n)
	{
		if (v[i].idx == k)
		{
			int idx = i;
			while (idx > 0 and v[idx] == v[idx - 1]) 
				idx--;
			cout << idx + 1;
			return;
		}
	}
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solution();
	return 0;
}