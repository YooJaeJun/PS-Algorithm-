#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using db = deque<bool>;
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define forn(i, n) for (int i = 0; i < (int)n; i++)
const int maxn = 1e9 + 7;
const double mod = 1e9 + 7;

struct town
{
	int dist, node;
	bool operator>(const town& other) const
	{
		return dist > other.dist;
	}
};

int n;
vvi dist;
vector<vector<town>> nodes;

void dijk(int start, int end)
{
	priority_queue<town, vector<town>, greater<town>> pq;
	pq.push({ 0, start });
	while (false == pq.empty())
	{
		int cur = pq.top().node;
		int distance = pq.top().dist;
		pq.pop();
		
		if (dist[start][cur] < distance) continue;

		for (auto& elem : nodes[cur])
		{
			int next = elem.node;
			int nDistance = elem.dist + distance;
			if (dist[start][next] > nDistance)
			{
				dist[start][next] = nDistance;
				pq.push({ nDistance, next });
			}
		}
	}
}

void solution()
{
	int m, x;
	cin >> n >> m >> x;
	nodes.resize(n + 1);
	dist = vvi(n + 1, vi(n + 1, maxn));

	forn(i, m)
	{
		int n1, n2, t;
		cin >> n1 >> n2 >> t;
		nodes[n1].push_back({ t, n2 });
	}

	for (int i = 1; i <= n; i++)
	{
		if (i != x)	dijk(i, x);
		else
		{
			for (int j = 1; j <= n; j++)
			{
				dijk(x, j);
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i != x)
		{
			if (dist[i][x] != maxn and dist[x][i] != maxn and
				ans < dist[i][x] + dist[x][i])
			{
				ans = dist[i][x] + dist[x][i];
			}
		}
	}
	cout << ans;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}