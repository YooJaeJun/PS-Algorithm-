#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
string nodes[101];
int visited[101][101];
int n, m;
int w = 1, b = 1;

void dfs(int x, int y, const char ch) {
	visited[x][y] = 1;
	for (int i = 0; i != 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 1 && nx <= m &&
			ny >= 1 && ny <= n &&
			visited[nx][ny] == 0 &&
			nodes[nx][ny] == nodes[x][y]) {

			switch (ch)	{
			case 'W':
				w++;
				break;
			case 'B':
				b++;
				break;
			}
			dfs(nx, ny, ch);
		}
	}
}

int main() {
	cin >> n >> m;
	for (int x = 1; x <= m; x++) {
		string s;
		cin >> s;
		nodes[x] += ' ' + s;
	}

	int sumW = 0, sumB = 0;
	for (int x = 1; x <= m; x++) {
		for (int y = 1; y <= n; y++) {
			if (visited[x][y] == 0) {
				if (nodes[x][y] == 'W') {
					dfs(x, y, 'W');
					sumW += w * w;
					w = 1;
				}
				if (nodes[x][y] == 'B') {
					dfs(x, y, 'B');
					sumB += b * b;
					b = 1;
				}
			}
		}
	}
	cout << sumW << ' ' << sumB;
	return 0;
}