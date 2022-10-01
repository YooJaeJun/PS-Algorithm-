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
	vi ans, v;
	int maxSize = 0;

	forn1(i, n)
	{
		v.clear();
		int a = n, b = i;

		while (a - b >= 0)
		{
			v.push_back(a);
			a -= b;
			swap(a, b);
		}
		v.push_back(a);
		v.push_back(b);

		if (maxSize < v.size())
		{
			maxSize = v.size();
			ans = v;
		}
	}

	cout << ans.size() << '\n';
	for (auto& elem : ans)
	{
		cout << elem << ' ';
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