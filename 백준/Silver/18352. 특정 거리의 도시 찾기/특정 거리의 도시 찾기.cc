#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int inf = 99999999;
int v, e;
vector<vector<pair<int, int>>> nodes;
vector<int> visited;
vector<int> dist;

void dijk(int start) {
	dist[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ start, 0 });
	
	while (pq.empty() == false) {
		int cur = pq.top().first;
		int distance = -pq.top().second;
		pq.pop();
		if (dist[cur] < distance) continue;

		for (int i = 0; i < nodes[cur].size(); i++) {
			int next = nodes[cur][i].first;
			int nextDistance = distance + nodes[cur][i].second;
			if (dist[next] > nextDistance) {
				dist[next] = nextDistance;
				pq.push({ next, -nextDistance });
			}
		}
	}
}

void solution() {
	int k, x;
	cin >> v >> e >> k >> x;
	nodes.resize(v + 1);
	visited.resize(v + 1);
	dist.resize(v + 1);

	for (int i = 1; i <= v; i++) {
		dist[i] = inf;
	}
	for (int i = 1; i <= e; i++) {
		int u, v;
		cin >> u >> v;
		nodes[u].push_back({ v, 1 });
	}

	dijk(x);

	bool isAns = false;
	for (int i = 1; i <= v; i++) {
		if (dist[i] == k) {
			isAns = true;
			cout << i << '\n';
		}
	}
	if (isAns == false) {
		cout << -1;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	//cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}