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
	int u, n;
	cin >> u >> n;
	
	unordered_map<int, string> dic1;
	map<int, int> dic2;

	forn(i, n)
	{
		string s;
		cin >> s;
		int p;
		cin >> p;

		if (dic1[p] == "") dic1[p] = s;
		dic2[p]++;
	}

	int minCnt = 1e9, minIdx = 0;

	for (auto& elem : dic2)
	{
		if (minCnt > elem.second)
		{
			minCnt = elem.second;
			minIdx = elem.first;
		}
	}

	cout << dic1[minIdx] << ' ' << minIdx;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solution();
	return 0;
}