#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
vector<vector<int>> nodes;
int n, m;
vector<vector<int>> dis;
int ans;

void bfs(vector<pair<int, int>>& starts) {
	queue<pair<int, int>> q;
	for (auto& start : starts) {
		q.push(start);
	}
	while (false == q.empty()) {
		int x_ = q.front().first;
		int y_ = q.front().second;
		q.pop();
		for (int i = 0; i != 4; i++) {
			int nx = x_ + dx[i];
			int ny = y_ + dy[i];
			if (nx >= 1 && nx <= n &&
				ny >= 1 && ny <= m &&
				nodes[nx][ny] == 0) {

				q.push({ nx, ny });
				nodes[nx][ny] = 1;	// 1이 익음
				dis[nx][ny] = dis[x_][y_] + 1;
				ans = dis[nx][ny];
				ans = ans;
			}
		}

	}
}

int main() {
	scanf("%d %d", &m, &n);
	nodes.resize(n + 1);
	dis.resize(n + 1);
	for (int x = 1; x <= n; x++) {
		nodes[x].resize(m + 1);
		dis[x].resize(m + 1);

		for (int y = 1; y <= m; y++) {
			scanf("%d", &nodes[x][y]);
		}
	}

	vector<pair<int, int>> starts;
	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= m; y++) {
			if (nodes[x][y] == 1) {
				starts.push_back({ x, y });
			}
		}
	}

	bfs(starts);
	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= m; y++) {
			if (nodes[x][y] == 0) {
				printf("-1");
				return 0;
			}
		}
	}
	printf("%d", ans);
	return 0;
}