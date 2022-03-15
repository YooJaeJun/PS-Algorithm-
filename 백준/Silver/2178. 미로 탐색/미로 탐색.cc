#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<string> nodes;
int dis[101][101];
bool visited[101][101];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int n, m;

void bfs() {
	queue<pair<int, int>> q;
	q.push({ 1, 1 });
	visited[1][1] = true;
	while (false == q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i != 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 1 && nx <= n &&
				ny >= 1 && ny <= m &&
				visited[nx][ny] == false &&
				nodes[nx][ny] == 1 + '0') {

				visited[nx][ny] = true;
				dis[nx][ny] = dis[x][y] + 1;
				q.push({ nx, ny });
			}
		}
	}
}

int main() {
	cin >> n >> m;
	nodes.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		nodes[i] += ' ' + s;
	}
	dis[1][1] = 1;
	bfs();
	cout << dis[n][m];
	return 0;
}