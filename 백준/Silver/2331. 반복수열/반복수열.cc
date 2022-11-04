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
	int a, p;
	cin >> a >> p;

	unordered_map<int, pair<int, int>> dic;
	dic[a] = {1, 0};
	string s = to_string(a);
	int idx = 1;

	while (1)
	{
		int sum = 0;
		for (auto& elem : s)
		{
			sum += pow(elem - '0', p);
		}

		if (dic[sum].first)
		{
			cout << dic[sum].second;
			return;
		}

		dic[sum] = {1, idx};
		s = to_string(sum);
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