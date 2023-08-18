#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> nodes;
vector<vector<vector<int>>> visited;	// 벽 부순 세계, 안 부순 세계의 거리
int n, m;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void bfs() {
	queue<pair<pair<int, int>, int>> q;
	q.push({ { 0, 0 }, 1 });
	
	while (q.empty() == false) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int chance = q.front().second;
		q.pop();

		for (int i = 0; i != 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (visited[nx][ny][chance]) continue;

			if (nodes[nx][ny] == 1 && chance) {
				visited[nx][ny][chance - 1] = visited[x][y][chance] + 1;
				q.push({ { nx, ny }, chance - 1 });
			}
			else if (nodes[nx][ny] == 0) {
				visited[nx][ny][chance] = visited[x][y][chance] + 1;
				q.push({ {nx,ny}, chance });
			}
		}
	}
}

void solution() {
	cin >> n >> m;
	nodes.resize(n);
	visited.resize(n);
	for (int i = 0; i != n; i++) {
		nodes[i].resize(m);
		visited[i].resize(m);
		for (int j = 0; j != m; j++) {
			visited[i][j].resize(2);
		}
	}

	string s;
	for (int i = 0; i != n; i++) {
		cin >> s;
		for (int j = 0; j != m; j++) {
			nodes[i][j] = s[j] - '0';
		}
	}

	visited[0][0][1] = 1;
	bfs();

	if (visited[n - 1][m - 1][0] == 0 && visited[n - 1][m - 1][1] == 0) {
		cout << -1;
	}
	else if(visited[n - 1][m - 1][0] == 0) {
		cout << visited[n - 1][m - 1][1];
	}
	else {
		cout << visited[n - 1][m - 1][0];
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}