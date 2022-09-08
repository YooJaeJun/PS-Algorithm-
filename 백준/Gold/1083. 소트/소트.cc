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
	forn(i, n) cin >> v[i];
	int s;
	cin >> s;

	forn(i, n - 1)
	{
		if (s == 0) break;
		auto end = i + s + 1 >= n ? v.end() : v.begin() + i + s + 1;
		int maxIdx = max_element(v.begin() + i, end) - v.begin();
		if (i == maxIdx) continue;
		int temp = v[maxIdx];
		v.erase(v.begin() + maxIdx);
		v.insert(v.begin() + i, temp);
		s -= (maxIdx - i);
	}

	forn(i, n) cout << v[i] << ' ';
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solution();
	return 0;
}