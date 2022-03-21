#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> nodes;
vector<vector<bool>> visited;
vector<bool> visitedAlpha;
int r, c;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int ans = 0;

void dfs(int x, int y, int cnt) {
	visited[x][y] = true;
	visitedAlpha[nodes[x][y] - 'A'] = true;

	for (int i = 0; i != 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < r &&
			ny >= 0 && ny < c &&
			visited[nx][ny] == false &&
			visitedAlpha[nodes[nx][ny] - 'A'] == false) {

			dfs(nx, ny, cnt + 1);
		}
	}

	visited[x][y] = false;
	visitedAlpha[nodes[x][y] - 'A'] = false;
	ans = max(ans, cnt);
}

void solution() {
	cin >> r >> c;
	nodes.resize(r);
	visited.resize(r);
	visitedAlpha.resize(26);
	for (int i = 0; i != r; i++) {
		nodes[i].resize(c);
		visited[i].resize(c);
	}
	for (int i = 0; i != r; i++) {
		for (int j = 0; j != c; j++) {
			cin >> nodes[i][j];
		}
	}

	dfs(0, 0, 1);
	
	cout << ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}