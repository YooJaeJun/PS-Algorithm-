#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int n, m;
char grid[10][11];
int visited[10][10][10][10] = { 0, };
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

struct board {
	int rx, ry, bx, by, depth;
};
board start;

void moveBid(int& x, int& y, const int i) {
	while (1) {
		if (grid[x][y] == '.' || grid[x][y] == 'R' || grid[x][y] == 'B') {
			x += dx[i];
			y += dy[i];
		}
		else if (grid[x][y] == 'O') {
			break;
		}
		else if (grid[x][y] == '#') {
			x -= dx[i];
			y -= dy[i];
			break;
		}
	}
}

int bfs() {
	queue<board> q;
	q.push(start);
	visited[start.rx][start.ry][start.bx][start.by] = true;

	while (q.empty() == false) {
		board cur = q.front();
		q.pop();

		if (cur.depth > 10) {
			return -1;
		}
		if (grid[cur.rx][cur.ry] == 'O' && grid[cur.bx][cur.by] != 'O') {
			return cur.depth;
		}

		for (int i = 0; i != 4; i++) {
			int nrx = cur.rx;
			int nry = cur.ry;
			int nbx = cur.bx;
			int nby = cur.by;

			moveBid(nrx, nry, i);
			moveBid(nbx, nby, i);

			if (nrx == nbx && nry == nby) {
				if (grid[nrx][nry] != 'O') {
					int rMoveDist = abs(nrx - cur.rx) + abs(nry - cur.ry);
					int bMoveDist = abs(nbx - cur.bx) + abs(nby - cur.by);
					if (rMoveDist > bMoveDist) {
						nrx -= dx[i];
						nry -= dy[i];
					}
					else {
						nbx -= dx[i];
						nby -= dy[i];
					}
				}
			}

			if (visited[nrx][nry][nbx][nby]) continue;
			visited[nrx][nry][nbx][nby] = true;

			q.push({ nrx, nry, nbx, nby, cur.depth + 1 });
		}
	}

	return -1;
}

void solution() {
	cin >> n >> m;
	for (int i = 0; i != n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j != m; j++) {
			grid[i][j] = s[j];
			if (grid[i][j] == 'R') {
				start.rx = i;
				start.ry = j;
			}
			else if (grid[i][j] == 'B') {
				start.bx = i;
				start.by = j;
			}
		}
	}

	cout << bfs();
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}