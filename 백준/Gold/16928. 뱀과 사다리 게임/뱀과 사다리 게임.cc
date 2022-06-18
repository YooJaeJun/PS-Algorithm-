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

unordered_map<int, int> road;
vi dist(101);

void bfs()
{
	queue<int> q;
	q.push(1);

	while (false == q.empty())
	{
		int x = q.front();
		q.pop();

		for (int i = 1; i <= 6; i++)
		{
			int nx = road[x + i];
			if (nx <= 0 || nx > 100) continue;
			if (dist[nx] and dist[nx] <= dist[x] + 1) continue;
			dist[nx] = dist[x] + 1;
			q.push(nx);
		}
	}
}

void solution()
{
	int n, m;
	cin >> n >> m;

	forn(i, 106)
	{
		road[i] = i;
	}
	forn(i, n)
	{
		int n1, n2;
		cin >> n1 >> n2;
		road[n1] = n2;
	}
	forn(i, m)
	{
		int n1, n2;
		cin >> n1 >> n2;
		road[n1] = n2;
	}

	bfs();

	cout << dist[100];
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}