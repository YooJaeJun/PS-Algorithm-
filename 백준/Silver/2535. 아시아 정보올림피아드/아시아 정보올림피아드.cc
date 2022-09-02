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
	int country, idx, score;
	struct info 
	{ 
		int country, idx, score;
		bool operator<(const info& other) { return score > other.score; }
	};
	vector<info> sorted(n);
	forn(i, n)
	{
		cin >> country >> idx >> score;
		sorted[i] = { country, idx, score };
	}
	sort(sorted.begin(), sorted.end());

	unordered_map<int, int> check;
	int confirm = 0;
	forn(i, n)
	{
		if (check[sorted[i].country] < 2)
		{
			cout << sorted[i].country << ' ' << sorted[i].idx << '\n';
			check[sorted[i].country]++;
			confirm++;
		}
		if (confirm == 3) break;
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