#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> nodes;
vector<vector<int>> dist;
vector<int> visited;

void bfs() {
	queue<pair<int, int>> q;	// idx, dist
	q.push({ 1, 0 });
	visited[1] = true;

	while (q.empty() == false) {
		int idx = q.front().first;
		int distance = q.front().second;
		q.pop();

		for (auto& elem : nodes[idx]) {
			if (visited[elem]) continue;
			dist[1][elem] = min(dist[1][elem], distance + 1);
			visited[elem] = true;
			q.push({ elem, distance + 1 });
		}
	}
}

int solution(int n, vector<vector<int>> edge) {
	nodes.resize(n + 1);
	visited.resize(n + 1);
	for (int i = 0; i < edge.size(); i++) {
		nodes[edge[i][0]].push_back(edge[i][1]);
		nodes[edge[i][1]].push_back(edge[i][0]);
	}
	dist.resize(2);
	dist[1].resize(n + 1, 1e9);

	bfs();

	int ans = 0;
	int max1 = 0;
	for (auto& elem : dist[1]) {
		if (elem != 1e9 && max1 < elem) {
			max1 = elem;
		}
	}
	for (auto& elem : dist[1]) {
		if (max1 == elem) {
			ans++;
		}
	}
	return ans;
}