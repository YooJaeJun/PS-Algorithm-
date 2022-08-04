#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using db = deque<bool>;
using ddb = deque<deque<bool>>;
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define forn1(i, n) for (int i = 1; i <= (int)n; i++)
#define inGrid() ((nr >= 0) and (nr < n) and (nc >= 0) and (nc < n))
int dr[4] = { 0,0,-1,1 };
int dc[4] = { -1,1,0,0 };	// 좌우상하

int n;
int ans = 0;
const int maxMoveCnt = 5;
vi limit(maxMoveCnt + 1);	// 뎁스별 제한값
ddb alreadyMerge;
vvi curBoard;

void goBack(vvi& curBoard, const int x, const int y, int nx, int ny, int i)
{
	nx -= dr[i];
	ny -= dc[i];
	if (curBoard[nx][ny] == 0)
	{
		curBoard[nx][ny] = curBoard[x][y];
		curBoard[x][y] = 0;
	}
}

bool move(vvi& board, const int dir)
{
	bool moved = false;	// 안 움직였으면 dfs no
	// 좌0 우1 상2 하3... r == row, c == column, coef == 증감용
	int startR = 0, startC = 0, endR = n, endC = n, coefR = 1, coefC = 1;
	if (dir == 1) startR = 0, startC = n - 1, endR = n, endC = -1, coefR = 1, coefC = -1;
	else if (dir == 3) startR = n - 1, startC = 0, endR = -1, endC = n, coefR = -1, coefC = 1;

	for (int r = startR; r != endR; r += coefR)
	{
		for (int c = startC; c != endC; c += coefC)
		{
			if (board[r][c] == 0) continue;
			if (alreadyMerge[r][c]) continue;

			int nr = r + dr[dir];
			int nc = c + dc[dir];
			while (1)
			{
				if (inGrid() == false)
				{
					goBack(board, r, c, nr, nc, dir);
					break;
				}
				if (board[nr][nc] != 0)
				{
					if (alreadyMerge[nr][nc] || (board[nr][nc] != board[r][c]))
					{
						goBack(board, r, c, nr, nc, dir);
					}
					else
					{
						board[nr][nc] *= 2;
						board[r][c] = 0;
						alreadyMerge[nr][nc] = true;
						moved = true;
					}
					break;
				}
				nr += dr[dir];
				nc += dc[dir];
				moved = true;
			}
		}
	}
	return moved;
}

void dfs(vvi& board, int depth)
{
	// cout << '\n'; forn(r, n) { forn(c, n) { cout << board[r][c] << ' '; } cout << '\n'; } cout << '\n';

	int curMax = 0;
	forn(r, n) forn(c, n) curMax = max(curMax, board[r][c]);

	// 현재 뎁스에서 최대값 만들기 불가능
	if (curMax <= limit[depth]) return;

	// 끝까지 갔을 때 depth별 limit 설정
	if (depth == maxMoveCnt)
	{
		ans = max(ans, curMax);
		limit[maxMoveCnt] = ans;
		for (int i = maxMoveCnt; i > 0; i--)
			limit[i - 1] = limit[i] / 2;
		return;
	}
	
	vvi boardOrigin = board;
	forn(r, n) forn(c, n) boardOrigin[r][c] = board[r][c];

	// 방향별 이동
	forn(dir, 4)
	{
		forn(i, n) fill(alreadyMerge[i].begin(), alreadyMerge[i].end(), false);	// 한 번 합쳐졌었나

		// 이 방향에서 움직여도 변화 없었으면 더 이상 x
		if (move(board, dir))
		{
			dfs(board, depth + 1);
			forn(r, n) forn(c, n) board[r][c] = boardOrigin[r][c];
		}
	}
}

void solution() {
	cin >> n;
	vvi board(n, vi(n));
	alreadyMerge = ddb(n, db(n));
	curBoard = vvi(n, vi(n));

	for (int i = 0; i != n; i++)
	{
		for (int j = 0; j != n; j++)
		{
			cin >> board[i][j];
			ans = max(ans, board[i][j]);
		}
	}

	dfs(board, 0);
	cout << ans;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solution();
	return 0;
}