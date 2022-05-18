#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
#define yes cout << "YES\n";
#define no cout << "NO\n";
const int maxn = 100'001;
const double mod = 1e9 + 7;

int n;
vvi nodes;
vi deg;

void topoSort()
{
	priority_queue<int, vi, greater<int>> pq;
	for (int i = 1; i <= n; i++)
		if (deg[i] == 0)
			pq.push(i);

	while (pq.empty() == false)
	{
		int cur = pq.top();
		pq.pop();
		cout << cur << ' ';

		for (auto& nxt : nodes[cur])
		{
			if (--deg[nxt] == 0)
			{
				pq.push(nxt);
			}
		}
	}
}

void solution()
{
	int m;
	cin >> n >> m;
	nodes = vvi(n + 1);
	deg = vi(n + 1);
	
	for (int i = 0; i < m; ++i)
	{
		int n1, n2;
		cin >> n1 >> n2;
		nodes[n1].push_back(n2);
		deg[n2]++;
	}

	for (int i = 1; i <= n; i++)
	{
		sort(nodes[i].begin(), nodes[i].end());
	}

	topoSort();
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}