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
#define gridCheck() if (nx < 0 or nx >= n or ny < 0 or ny >= n) continue;

struct tagNode
{
	int dist, node;
	bool operator>(const tagNode& other) const
	{
		return dist > other.dist;
	}
};

void solution()
{
	int n, m;
	cin >> n >> m;
	vector<vector<tagNode>> nodes(n + 1);
	forn(i, m)
	{
		int s, e, d;
		cin >> s >> e >> d;
		nodes[s].push_back({ d, e });
	}

	int start, end;
	cin >> start >> end;
	vi dist(n + 1, maxn);
	dist[start] = 0;
	vi history(n + 1);

	auto dijk = [&]()
	{
		priority_queue<tagNode, vector<tagNode>, greater<tagNode>> pq;
		pq.push({ 0, start });

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

				if (dist[next] <= nDistance) continue;
				
				history[next] = cur;	//
				dist[next] = nDistance;
				pq.push({ nDistance, next });
			}
		}
	};
	dijk();

	cout << dist[end] << '\n';
	
	int node = end;
	vi ansHistory;
	forn(i, n)
	{
		ansHistory.push_back(node);
		node = history[node];
		if (node == 0) break;
	}
	cout << ansHistory.size() << '\n';
	for (int i = ansHistory.size() - 1; i >= 0; i--) cout << ansHistory[i] << ' ';
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solution();
	return 0;
}