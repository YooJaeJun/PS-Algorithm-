#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m, r;
	cin >> n >> m >> r;

	vector<vector<int>> adj(n + 1);

	while (m--)
	{
		int n1, n2;
		cin >> n1 >> n2;
		adj[n1].push_back(n2);
		adj[n2].push_back(n1);
	}

	for (auto& elem : adj)
		sort(elem.begin(), elem.end());

	vector<int> visited(n + 1);
	int cnt = 1;

	auto Bfs = [&]()
	{
		queue<int> q;
		q.push(r);
		visited[r] = cnt++;

		while (false == q.empty())
		{
			int cur = q.front();
			q.pop();

			for (auto& elem : adj[cur])
			{
				if (visited[elem])
					continue;
				visited[elem] = cnt++;
				q.push(elem);
			}
		}
	};
	Bfs();

	for (int i = 1; i <= n; i++)
		cout << visited[i] << '\n';

	return 0;
}
