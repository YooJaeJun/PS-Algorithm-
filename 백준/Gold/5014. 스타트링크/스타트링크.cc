#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using db = deque<bool>;
using ddb = deque<deque<bool>>;
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define forn1(i, n) for (int i = 1; i <= (int)n; i++)
const int maxn = 1e9 + 7;
const double mod = 1e9 + 7;
#define checkInGrid() if (nx < 0 or nx >= n or ny < 0 or ny >= m) continue;


void solution()
{
	int f, s, g, u, d;
	cin >> f >> s >> g >> u >> d;
	int ans = 1e9;

	function<void()> bfs = [&]()
	{
		queue<pii> q;
		q.push({ s, 0 });
		db visited(f + 1);
		visited[s] = true;

		while (q.empty() == false)
		{
			int x = q.front().first;
			int cnt = q.front().second;
			q.pop();
			if (x == g)
			{
				ans = min(ans, cnt);
				continue;
			}

			for (auto next : { x + u, x - d })
			{
				if (next < 1 or next > f) continue;
				if (visited[next]) continue;
				visited[next] = true;
				q.push({ next, cnt + 1 });
			}
		}
	};
	bfs();

	if (ans == 1e9) cout << "use the stairs";
	else cout << ans;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solution();
	return 0;
}