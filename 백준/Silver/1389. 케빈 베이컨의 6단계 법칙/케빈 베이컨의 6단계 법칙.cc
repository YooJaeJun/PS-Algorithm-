#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int inf = 9999999;
int n, m;
vector<vector<pair<int, int>>> nodes;
vector<vector<int>> dist;

void dijk(int start, vector<int>& d) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	d[start] = 0;
	pq.push({ 0, start });

	while (pq.empty() == false) {
		int distance = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (d[cur] < distance) continue;
		
		for (int i = 0; i < nodes[cur].size(); i++) {
			int nextDistance = distance + nodes[cur][i].first;
			int next = nodes[cur][i].second;
			
			if (d[next] > nextDistance) {
				d[next] = nextDistance;
				pq.push({ nextDistance, next });
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
		int u, v;
		cin >> u >> v;
		nodes[u].push_back({ 1, v });
		nodes[v].push_back({ 1, u });
	}

	for (int i = 1; i <= n; i++) {
		dijk(i, dist[i]);
	}
	
	int ansIdx = inf, ans = inf;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			sum += dist[i][j];
		}
		if (ans > sum) {
			ans = sum;
			ansIdx = i;
		}
	}
	cout << ansIdx;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	//cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}