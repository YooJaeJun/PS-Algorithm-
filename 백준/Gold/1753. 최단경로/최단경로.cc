#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int inf = 99999999;
int v, e;
vector<vector<pair<int, int>>> nodes;	// 가중치, 끝점
vector<int> visited;
vector<int> dist;

void dijk(int start) {
	dist[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;	// 가중치 작은 것부터
	pq.push({ 0, start });
	
	while (pq.empty() == false) {
		int distance = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (dist[cur] < distance) continue;

		for (int i = 0; i < nodes[cur].size(); i++) {
			int nextDistance = distance + nodes[cur][i].first;
			int next = nodes[cur][i].second;

			if (dist[next] > nextDistance) {
				dist[next] = nextDistance;
				pq.push({ nextDistance, next });
			}
		}
	}
}

void solution() {
	cin >> v >> e;
	nodes.resize(v + 1);
	visited.resize(v + 1);
	dist.resize(v + 1);

	int start;
	cin >> start;

	for (int i = 1; i <= v; i++) {
		dist[i] = inf;
	}
	for (int i = 1; i <= e; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		nodes[u].push_back({ w, v });
	}

	dijk(start);

	for (int i = 1; i <= v; i++) {
		if (dist[i] == inf) cout << "INF" << '\n';
		else cout << dist[i] << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	//cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}