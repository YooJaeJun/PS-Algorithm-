#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<vector<pair<int, int>>> nodes;	// 가중치, 끝점
vector<int> dist;
const int inf = 1e9;

void dijk(int start) {
	dist[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start });

	while (pq.empty() == false) 
	{
		int cur = pq.top().second;
		int distance = pq.top().first;
		pq.pop();

		if (dist[cur] < distance) continue;

		for (auto& elem : nodes[cur]) {
			int next = elem.second;
			int nDistance = distance + elem.first;
			if (dist[next] > nDistance) {
				dist[next] = nDistance;
				pq.push({ nDistance, next });
			}
		}
	}
}

void solution() {
	int v, e, k;
	cin >> v >> e >> k;
	nodes.resize(v + 1);
	dist = vector<int>(v + 1, inf);
	
	for (int i = 1; i <= e; i++) {
		int n1, n2, d;
		cin >> n1 >> n2 >> d;
		nodes[n1].push_back({ d, n2 });
	}

	dijk(k);

	for (int i = 1; i != dist.size(); i++) {
		if (dist[i] == inf) cout << "INF" << '\n';
		else cout << dist[i] << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}