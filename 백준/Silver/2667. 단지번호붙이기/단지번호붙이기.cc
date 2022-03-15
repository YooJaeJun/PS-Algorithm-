#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int n;
int visited[26][26] = { 0, };
int nodes[26][26] = { 0, };
vector<int> counts;

void dfs(int x, int y) {
	visited[x][y] = 1;
	for (int i = 0; i != 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 1 && nx <= n &&
			ny >= 1 && ny <= n &&
			visited[nx][ny] == 0 &&
			nodes[nx][ny] == 1) {

			visited[nx][ny] = 1;
			counts.back()++;
			dfs(nx, ny);
		}
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		char s[26];
		scanf("%s", s);
		for (int j = 1; j <= n; j++) {
			nodes[i][j] = s[j - 1] - '0';
		}
	}
	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= n; y++) {
			if (visited[x][y] == 0 && nodes[x][y] == 1) {
				counts.push_back(1);
				dfs(x, y);
			}
		}
	}
	printf("%d\n", counts.size());
	sort(counts.begin(), counts.end());
	for (auto& count : counts) {
		printf("%d\n", count);
	}
	return 0;
}