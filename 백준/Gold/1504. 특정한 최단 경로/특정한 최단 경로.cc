#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
#define yes cout << "YES\n";
#define no cout << "NO\n";
const int maxn = 1e9 + 7;
const double mod = 1e9 + 7;

struct road
{
	int dist, node;
	bool operator>(road other) const
	{
		return dist > other.dist;
	}
};

int n, e;
vector<vector<road>> nodes;
vi dist, visited;

void dijk(int start, int end)
{
	priority_queue<road, vector<road>, greater<road>> pq;
	pq.push({ 0, start });
	visited[start] = true;

	while (pq.empty() == false)
	{
		int cur = pq.top().node;
		int distance = pq.top().dist;
		pq.pop();

		if (dist[cur] < distance) continue;

		for (auto& elem : nodes[cur])
		{
			int next = elem.node;
			int nDistance = distance + elem.dist;
			if (dist[next] > nDistance)
			{
				dist[next] = nDistance;
				pq.push({ nDistance, next });
				visited[next] = true;
			}
		}
	}
}

int passThrough(int v1, int v2)
{
	int history = 0;

	if (1 != v1)
	{
		fill(dist.begin(), dist.end(), maxn);
		dijk(1, v1);
		if (dist[v1] >= maxn) return maxn;
		history += dist[v1];
	}

	fill(dist.begin(), dist.end(), maxn);
	dijk(v1, v2);
	if (dist[v1] >= maxn) return maxn;
	history += dist[v2];

	if (n != v2)
	{
		fill(dist.begin(), dist.end(), maxn);
		dijk(v2, n);
		if (dist[v1] >= maxn) return maxn;
		history += dist[n];
	}

	return history;
}

void solution()
{
	cin >> n >> e;
	nodes.resize(n + 1);
	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		nodes[a].push_back({ c, b });
		nodes[b].push_back({ c, a });
	}
	visited.resize(n + 1);
	dist = vi(n + 1, maxn);

	int v1, v2;
	cin >> v1 >> v2;
	int ans = maxn;

	int history1 = passThrough(v1, v2);
	int history2 = passThrough(v2, v1);
	ans = min(history1, history2);

	if (ans >= maxn) cout << -1;
	else cout << ans;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}