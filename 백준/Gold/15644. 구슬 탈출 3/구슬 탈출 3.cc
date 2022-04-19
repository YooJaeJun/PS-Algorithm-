#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int n, m;
char board[10][11];
int visited[10][10][10][10] = { 0, };
int dx[4] = { 0,0,-1,1 };	// 좌우상하
int dy[4] = { -1,1,0,0 };
string commands;

enum class eCommand {
	left, right, up, down
};
string commandList = "LRUD";

struct gameState {
	int rx, ry, bx, by, depth;
	string command;
};
gameState start;


void moveBid(int& x, int& y, const int i, bool& moveOnce) {
	while (1) {
		if (board[x][y] == '.' || board[x][y] == 'R' || board[x][y] == 'B') {
			moveOnce = true;
			x += dx[i];
			y += dy[i];
		}
		else if (board[x][y] == 'O') {
			break;
		}
		else if (board[x][y] == '#') {
			x -= dx[i];
			y -= dy[i];
			break;
		}
	}
}

int bfs() {
	queue<gameState> q;
	q.push(start);
	visited[start.rx][start.ry][start.bx][start.by] = true;

	while (q.empty() == false) {
		gameState cur = q.front();
		q.pop();

		if (cur.depth > 10) {
			return -1;
		}
		if (board[cur.rx][cur.ry] == 'O' && board[cur.bx][cur.by] != 'O') {
			commands = cur.command;
			return cur.depth;
		}

		for (int i = 0; i != 4; i++) {
			int nrx = cur.rx;
			int nry = cur.ry;
			int nbx = cur.bx;
			int nby = cur.by;

			bool moveOnce = false;
			moveBid(nrx, nry, i, moveOnce);
			moveBid(nbx, nby, i, moveOnce);

			if (nrx == nbx && nry == nby) {
				if (board[nrx][nry] != 'O') {
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
			q.push({ nrx, nry, nbx, nby, cur.depth + 1, cur.command + commandList[i] });
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
			board[i][j] = s[j];
			if (board[i][j] == 'R') {
				start.rx = i;
				start.ry = j;
			}
			else if (board[i][j] == 'B') {
				start.bx = i;
				start.by = j;
			}
		}
	}

	int n = bfs();
	cout << n << '\n';
	if (n != -1) cout << commands;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}