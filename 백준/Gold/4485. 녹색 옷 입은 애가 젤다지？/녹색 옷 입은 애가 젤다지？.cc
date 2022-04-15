#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int problemIdx = 1;
int n;
vector<vector<pair<int, int>>> nodes;	// 거리, 연결노드
vector<int> dist;
vector<vector<int>> grid;	// 그래프

void dijk() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ nodes[0][0].first, 0});

	while (pq.empty() == false) {
		int distance = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		
		if (dist[cur] < distance) continue;

		for (auto& elem : nodes[cur]) {
			int nDistance = distance + elem.first;
			int nCur = elem.second;

			if (dist[nCur] > nDistance) {
				dist[nCur] = nDistance;
				pq.push({ nDistance, nCur });
			}
		}
	}
}

void link() {
	for (int i = 0; i != n; i++) {
		for (int j = 0; j != n; j++) {
			int center = i * n + j;
			nodes[center].push_back({ grid[i][j], center });

			if (i > 0) {
				int top = (i - 1) * n + j;
				nodes[top].push_back({ grid[i][j], i * n + j });
				nodes[center].push_back({ grid[i - 1][j], top });
			}
			if (i < n - 1) {
				int bottom = (i + 1) * n + j;
				nodes[bottom].push_back({ grid[i][j], i * n + j });
				nodes[center].push_back({ grid[i + 1][j], bottom });
			}
			if (j < n - 1) {
				int right = i * n + (j + 1);
				nodes[right].push_back({ grid[i][j], i * n + j });
				nodes[center].push_back({ grid[i][j + 1], right });
			}
			if (j > 0) {
				int left = i * n + (j - 1);
				nodes[left].push_back({ grid[i][j], i * n + j });
				nodes[center].push_back({ grid[i][j - 1], left });
			}
		}
	}
}

void solution() {
	nodes.resize(n * n);
	dist.resize(n * n, 1e9);
	grid.resize(n);
	for (auto& elem : grid) {
		elem.resize(n);
	}

	for (int i = 0; i != n; i++) {
		for (int j = 0; j != n; j++) {
			cin >> grid[i][j];
		}
	}

	link();

	dijk();

	cout << "Problem " << problemIdx << ": " << dist[n * n - 1] << '\n';
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	while (1) {
		int total;
		cin >> total;
		if (total == 0) return 0;
		else {
			n = total;
			solution();
			problemIdx++;
			nodes.clear();
			dist.clear();
			grid.clear();
		}
	}
	return 0;
}