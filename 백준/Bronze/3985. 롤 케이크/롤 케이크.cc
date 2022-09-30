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
#define inGrid() ((nr >= 0) and (nr < r) and (nc >= 0) and (nc < c))
int dr[8] = { 0,0,-1,1,-1,1,-1,1 };
int dc[8] = { -1,1,0,0,-1,1,1,-1 };


void solution()
{
	int l;
	cin >> l;
	int n;
	cin >> n;

	int diffMax = 0, diffMaxIdx = 0;
	int most = 0, mostIdx = 0;
	map<int, bool> dic;

	forn(i, n)
	{
		int p, k;
		cin >> p >> k;

		if (diffMax < k - p + 1)
		{
			diffMax = k - p + 1;
			diffMaxIdx = i + 1;
		}

		int cur = 0;
		for (int j = p; j <= k; j++)
		{
			if (dic[j]) continue;
			dic[j] = true;
			cur++;
		}
		if (most < cur)
		{
			most = cur;
			mostIdx = i + 1;
		}
	}

	cout << diffMaxIdx << '\n' << mostIdx;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solution();
	return 0;
}