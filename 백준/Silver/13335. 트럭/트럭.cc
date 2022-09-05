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
	int n, w, l;
	cin >> n >> w >> l;
	queue<int> q;	// 대기 중 트럭(무게)
	forn(i, n)
	{
		int weight;
		cin >> weight;
		q.push(weight);
	}

	struct truck { int weight, cur; };
	deque<truck> dq;	// 다리 건너는 중인 트럭
	int t = 0;
	int curWeight = l;
	while (q.empty() == false or dq.empty() == false)
	{
		t++;
		// 다리 다 건넜니
		for (auto& elem : dq)
		{
			if (++elem.cur >= w)
			{
				curWeight += elem.weight;
				dq.pop_front();
			}
		}
		// 다리 들어가도 되니
		if (q.empty() == false and curWeight >= q.front())
		{
			curWeight -= q.front();
			dq.push_back({ q.front(), 0 });
			q.pop();
		}
	}
	cout << t;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solution();
	return 0;
}