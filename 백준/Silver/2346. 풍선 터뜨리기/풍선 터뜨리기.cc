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
	struct balloon { int num, idx; };
	deque<balloon> dq(n);
	forn(i, n)
	{
		cin >> dq[i].num;
		dq[i].idx = i + 1;
	}

	while (1)
	{
		cout << dq[0].idx << ' ';
		int move = dq[0].num;
		dq.pop_front();
		if (dq.empty()) break;

		if (move > 0)
		{
			forn(i, move - 1)
			{
				dq.push_back(dq.front());
				dq.pop_front();
			}
		}
		else
		{
			for (int i = move; i < 0; i++)
			{
				dq.push_front(dq.back());
				dq.pop_back();
			}
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