#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

vector<vector<pii>> nodes;	// 노드 - 거리, 연결노드
vi dist;

void dijk()
{
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ 0, 1 });	// 거리, 연결노드

	while (pq.empty() == false)
	{
		int cur = pq.top().second;
		int distance = pq.top().first;
		pq.pop();

		if (dist[cur] < distance) continue;

		for (auto& elem : nodes[cur])
		{
			int nxt = elem.second;
			int nDistance = elem.first + distance;

			if (dist[nxt] > nDistance)
			{
				dist[nxt] = nDistance;
				pq.push({ nDistance, nxt });
			}
		}
	}
}

void solution()
{
	int n, m;
	cin >> n >> m;
	nodes = vector<vector<pii>>(n + 1);
	dist = vi(n + 1, 1e9);

	for (int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		nodes[a].push_back({ c, b });
		nodes[b].push_back({ c, a });
	}

	dijk();

	cout << dist[n];
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}