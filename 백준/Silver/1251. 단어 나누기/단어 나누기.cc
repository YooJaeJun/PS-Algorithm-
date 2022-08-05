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
	string s;
	cin >> s;
	int size = s.size();
	string ans = "|";	// 알파벳보다 높은 아무 문자
	string sOrigin = s;
	for (int cut1 = 0; cut1 < size - 2; cut1++)
	{
		for (int cut2 = cut1 + 1; cut2 < size - 1; cut2++)
		{
			reverse(s.begin(), s.begin() + cut1 + 1);
			reverse(s.begin() + cut1 + 1, s.begin() + cut2 + 1);
			reverse(s.begin() + cut2 + 1, s.end());
			ans = min(ans, s);
			s = sOrigin;
		}
	}
	cout << ans;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solution();
	return 0;
}