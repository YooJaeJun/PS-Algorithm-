#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <functional>

using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m, v;
	cin >> n >> m >> v;

	vector<vector<int>> adj(n + 1);

	while (m--)
	{
		int n1, n2;
		cin >> n1 >> n2;
		adj[n1].push_back(n2);
		adj[n2].push_back(n1);
	}

	deque<bool> visited(n + 1);

	for (auto& elem : adj)
		sort(elem.begin(), elem.end());

	function<void(int)> DFS = [&](int start)
	{
		visited[start] = true;
		cout << start << ' ';

		for (auto& elem : adj[start])
		{
			if (visited[elem])
				continue;
			DFS(elem);
		}
	};
	DFS(v);

	cout << '\n';
	fill(visited.begin(), visited.end(), false);

	auto BFS = [&]()
	{
		queue<int> q;
		q.push(v);

		while (false == q.empty())
		{
			int cur = q.front();
			q.pop();
			visited[v] = true;
			cout << cur << ' ';

			for (auto& elem : adj[cur])
			{
				if (visited[elem])
					continue;
				visited[elem] = true;
				q.push(elem);
			}
		}
	};
	BFS();

	return 0;
}