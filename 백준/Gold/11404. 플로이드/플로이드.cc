#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int inf = 99999999;
vector<vector<pair<int, int>>> nodes;
vector<vector<int>> dist;
int n, m;

void dijk(int start, vector<int>& dist) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[start] = 0;
	pq.push({ 0, start });

	while (pq.empty() == false) {
		int distance = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		
		if (dist[cur] < distance) continue;	// 최단 거리 아니면 스킵

		for (int i = 0; i < nodes[cur].size(); i++) {	// 현재 최단거리 노드에 연결된 노드 검사
			int nextDistance = distance + nodes[cur][i].first;
			int next = nodes[cur][i].second;
			if (dist[next] > nextDistance) {
				dist[next] = nextDistance;
				pq.push({ dist[next], next });
			}
		}
	}
}

void solution() {
	cin >> n >> m;
	nodes.resize(n + 1);
	dist.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		dist[i].resize(n + 1, inf);
	}
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		nodes[u].push_back({ w, v });	// 가중치, 노드
	}

	for (int i = 1; i <= n; i++) {
		dijk(i, dist[i]);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == inf) cout << 0 << ' ';
			else cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	//cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}