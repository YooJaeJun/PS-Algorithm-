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

vvi nodes;
vi visited;
int order = 1;

void bfs(int start)
{
	queue<int> q;
	q.push(start);
	visited[start] = order++;

	while (false == q.empty())
	{
		int cur = q.front();
		q.pop();
		for (auto& next : nodes[cur])
		{
			if (visited[next]) continue;
			visited[next] = order++;
			q.push(next);
		}
	}
}

void solution()
{
	int n, m, r;
	cin >> n >> m >> r;
	nodes = vvi(n + 1);
	visited = vi(n + 1);
	forn(i, m)
	{
		int n1, n2;
		cin >> n1 >> n2;
		nodes[n1].push_back(n2);
		nodes[n2].push_back(n1);
	}
	
	for (int i = 1; i <= n; i++) sort(nodes[i].begin(), nodes[i].end());

	bfs(r);

	for (int i = 1; i <= n; i++) cout << visited[i] << '\n';
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}