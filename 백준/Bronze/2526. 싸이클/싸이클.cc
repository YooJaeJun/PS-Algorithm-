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
	int n, p;
	cin >> n >> p;

	int cur = n;
	unordered_map<int, pair<int, int>> dic;
	dic[n].first = 0;
	int idx = 1;

	while (true)
	{
		cur = (cur * n) % p;

		if (cur == 0)
		{
			if (!dic[cur].second)
			{
				cout << 1;
				return;
			}
		}

		if (dic[cur].second == cur)
		{
			cout << idx - dic[cur].first;
			return;
		}
		else
		{
			dic[cur].second = cur;
			dic[cur].first = idx;
		}

		idx++;
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