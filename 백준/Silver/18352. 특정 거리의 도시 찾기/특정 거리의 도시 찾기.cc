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
	const int inf = 1e9;

	vi dist;
	int n, m, k, x;
	cin >> n >> m >> k >> x;
	dist.resize(n + 1, inf);
	vector<vector<pii>> nodes(n + 1);

	forn1(i, m)
	{
		int u, v;
		cin >> u >> v;
		nodes[u].push_back({ v, 1 });
	}


	auto dijk = [&](int start)
	{
		dist[start] = 0;
		priority_queue<pii, vector<pii>, greater<pii>> pq;
		pq.push({ 0, start });
		
		while (pq.empty() == false)
		{
			int cur = pq.top().second;
			int distance = pq.top().first;
			pq.pop();
			
			if (dist[cur] < distance) continue;

			for (auto& elem : nodes[cur])
			{
				int next = elem.first;
				int nextDistance = distance + elem.second;

				if (dist[next] > nextDistance)
				{
					dist[next] = nextDistance;
					pq.push({ nextDistance, next });
				}
			}
		}
	};
	dijk(x);

	bool flag = false;
	forn1(i, n)
	{
		if (dist[i] == k)
		{
			flag = true;
			cout << i << '\n';
		}
	}
	if (!flag) cout << -1;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solution();
	return 0;
}