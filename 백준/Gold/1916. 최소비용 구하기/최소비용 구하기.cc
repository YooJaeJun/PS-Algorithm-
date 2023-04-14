#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void Solution()
{
	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, int>>> adj(n + 1);

	for (int i = 0; i < m; i++)
	{
		int n1, n2, dist;
		cin >> n1 >> n2 >> dist;
		adj[n1].push_back({ dist, n2 });
	}

	int start, end;
	cin >> start >> end;
	vector<int> dist(n + 1, 1e9);

	auto Dijk = [&]()
	{
		priority_queue<pair<int, int>> pq;
		pq.push({ 0, start });

		while(pq.empty() == false)
		{
			int curDist = pq.top().first;
			int cur = pq.top().second;
			pq.pop();

			if (dist[cur] < curDist)
				continue;

			for (auto& elem : adj[cur])
			{
				int nextDist = curDist + elem.first;
				int next = elem.second;

				if (dist[next] > nextDist)
				{
					dist[next] = nextDist;
					pq.push({ nextDist, next });
				}
			}
		}
	};
	Dijk();

	cout << dist[end];
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	Solution();
}