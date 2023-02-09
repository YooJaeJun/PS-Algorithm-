#include <iostream>
#include <vector>
#include <deque>
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
	string ans = "UCPC";
	int idx = 0;
	
	string s;
	while (cin >> s)
	{
		if (idx > 3)
			break;

		int cur = 0;
		for (auto& ch : s)
		{
			while (ch == ans[idx])
				idx++;
		}
	}

	if (idx == 4)
		cout << "I love UCPC";
	else
		cout << "I hate UCPC";
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solution();
	return 0;
}