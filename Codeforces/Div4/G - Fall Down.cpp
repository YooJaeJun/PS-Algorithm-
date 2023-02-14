#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

void dfs(vector<vector<char>>& grid, int x, int y) {
	int nx = x;
	while (1) {
		nx++;
		if (nx == n) {
			grid[x][y] = '.';
			grid[--nx][y] = '*';
			break;
		}
		if (grid[nx][y] == 'o') {
			grid[x][y] = '.';
			grid[--nx][y] = '*';
			break;
		}
		if (grid[nx][y] == '*') {
			grid[x][y] = '.';
			grid[--nx][y] = '*';
			break;
		}
	}
}

void solution() {
	cin >> n >> m;
	vector<vector<char>> grid(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}

	for (int i = n - 2; i >= 0; i--) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == '*') {
				dfs(grid, i, j);
			}
		}
	}

	for (int i = 0; i != n; i++) {
		for (int j = 0; j != m; j++) {
			cout << grid[i][j];
		}
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}