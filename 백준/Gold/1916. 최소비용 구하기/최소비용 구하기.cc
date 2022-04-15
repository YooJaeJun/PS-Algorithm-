#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int n, m;
vector<vector<pair<int, int>>> nodes;
vector<int> dist;
vector<bool> visited;
const int inf = 1e9;
int ans = inf;

void dijk(int start) {
	priority_queue<pair<int, int>> pq;	// 거리, 연결노드
	pq.push({ 0, start });

	while (pq.empty() == false) {
		int distance = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (dist[cur] < distance) continue;

		for (int i = 0; i != nodes[cur].size(); i++) {
			int nDistance = distance + nodes[cur][i].first;
			int nCur = nodes[cur][i].second;

			if (dist[nCur] > nDistance) {
				dist[nCur] = nDistance;
				pq.push({ nDistance, nCur });
			}
		}
	}
}

void solution() {
	cin >> n >> m;
	nodes.resize(n + 1);
	visited.resize(n + 1);
	dist.resize(n + 1, inf);

	for (int i = 0; i != m; i++) {
		int n1, n2, d;
		cin >> n1 >> n2 >> d;
		nodes[n1].push_back({ d, n2 });
	}

	int start, end;
	cin >> start >> end;
	dijk(start);

	cout << dist[end];
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}