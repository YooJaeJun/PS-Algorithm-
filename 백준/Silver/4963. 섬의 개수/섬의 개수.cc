#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int nodes[51][51] = { 0, };
int visited[51][51] = { 0, };
int w, h;
int cnt = 0;

void dfs(int x, int y) {
	for (int i = 0; i != 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 1 && nx <= h &&
			ny >= 1 && ny <= w &&
			visited[nx][ny] == 0 &&
			nodes[nx][ny] == 1) {

			visited[nx][ny] = 1;
			dfs(nx, ny);
		}
	}
}

int main() {
	while (1) {
		scanf("%d %d", &w, &h);
		if (w == 0 && h == 0) {
			break;
		}
		for (int x = 1; x <= h; x++) {
			for (int y = 1; y <= w; y++) {
				scanf("%d", &nodes[x][y]);
			}
		}
		for (int x = 1; x <= h; x++) {
			for (int y = 1; y <= w; y++) {
				if (nodes[x][y] == 1 && visited[x][y] == 0) {
					dfs(x, y);
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);
		for (int x = 1; x <= 51; x++) {
			for (int y = 1; y <= 51; y++) {
				nodes[x][y] = 0;
				visited[x][y] = 0;
			}
		}
		cnt = 0;
	}
	
	return 0;
}