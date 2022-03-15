#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int nodes[51][51];
bool visited[51][51];
int n, m;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int memo[51][51];

int dfs(int x, int y) {
	if (memo[x][y] != 0) {
		return memo[x][y];
	}
	visited[x][y] = true;
	memo[x][y] = 1;

	for (int i = 0; i != 4; i++) {
		int nx = x + dx[i] * nodes[x][y];
		int ny = y + dy[i] * nodes[x][y];
		if (nx >= 1 && nx <= n &&
			ny >= 1 && ny <= m &&
			nodes[nx][ny] != 24/*'H'*/) {
			if (visited[nx][ny]) {
				cout << -1;
				exit(0);
			}
			else {
				memo[x][y] = max(memo[x][y], dfs(nx, ny) + 1);
			}
		}
	}
	visited[x][y] = false;
	return memo[x][y];
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int x = 1; x <= n; x++) {
		string s;
		cin >> s;
		for (int y = 0; y < m; y++) {
			nodes[x][y + 1] = s[y] - '0';
		}
	}
	if (nodes[1][1] == 24/*'H'*/) {
		cout << -1;
		return 0;
	}
	cout << dfs(1, 1);
	return 0;
}