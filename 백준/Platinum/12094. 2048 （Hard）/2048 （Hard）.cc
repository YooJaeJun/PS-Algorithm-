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
const int maxMoveDepth = 10;
vi limit(maxMoveDepth + 1);
enum edir { left, right, top, bottom };
deque<int> dq;

void move(vvi& board, const int dir)
{
	// dq에다 각 줄마다 0이 아닌 거 넣고, 각 줄 처음부터 채워넣을거임. 행인지 열인지, 시작부턴지 끝부턴지 잘 생각
	dq.clear();

	int cur = 0;
	if (dir == edir::right or dir == edir::bottom) cur = n - 1;

	if (dir == edir::left)
	{
		forn(r, n)	//
		{
			forn(c, n)	//
			{
				if (board[r][c] == 0) continue;
				dq.push_back(board[r][c]);	//
				board[r][c] = 0;
			}
			while (false == dq.empty())
			{
				if (board[r][cur] == 0) board[r][cur] = dq.front();	//
				else if (board[r][cur] == dq.front()) board[r][cur++] *= 2;	//
				else board[r][++cur] = dq.front(); //
				dq.pop_front();
			}
			cur = 0;	//
		}
	}
	else if (dir == edir::right)
	{
		forn(r, n)	//
		{
			forn(c, n)	//
			{
				if (board[r][c] == 0) continue;
				dq.push_front(board[r][c]);	//
				board[r][c] = 0;
			}
			while (false == dq.empty())
			{
				if (board[r][cur] == 0) board[r][cur] = dq.front();	//
				else if (board[r][cur] == dq.front()) board[r][cur--] *= 2;	//
				else board[r][--cur] = dq.front(); //
				dq.pop_front();
			}
			cur = n - 1;	//
		}
	}
	else if (dir == edir::top)
	{
		forn(c, n)	//
		{
			forn(r, n)	//
			{
				if (board[r][c] == 0) continue;
				dq.push_back(board[r][c]);	//
				board[r][c] = 0;
			}
			while (false == dq.empty())
			{
				if (board[cur][c] == 0) board[cur][c] = dq.front();	//
				else if (board[cur][c] == dq.front()) board[cur++][c] *= 2;	//
				else board[++cur][c] = dq.front();	//
				dq.pop_front();
			}
			cur = 0;	//
		}
	}
	else if (dir == edir::bottom)
	{
		forn(c, n)	//
		{
			forn(r, n)	//
			{
				if (board[r][c] == 0) continue;
				dq.push_front(board[r][c]);	//
				board[r][c] = 0;
			}
			while (false == dq.empty())
			{
				if (board[cur][c] == 0) board[cur][c] = dq.front();	//
				else if (board[cur][c] == dq.front()) board[cur--][c] *= 2;	//
				else board[--cur][c] = dq.front();	//
				dq.pop_front();
			}
			cur = n - 1;	//
		}
	}
}

bool isSame(vvi& board, vvi& boardOrigin)
{
	forn(r, n) forn(c, n) if (board[r][c] != boardOrigin[r][c]) return false;
	return true;
}

void dfs(vvi& board, int depth)
{
	// cout << '\n'; forn(r, n) { forn(c, n) { cout << board[r][c] << ' '; } cout << '\n'; } cout << '\n';

	int curMax = 0;
	forn(r, n) forn(c, n) curMax = max(curMax, board[r][c]);

	// 현재 뎁스에서 최대값 만들기 불가능
	if (curMax <= limit[depth]) return;

	// 끝까지 갔을 때 depth별 limit 설정
	if (depth == maxMoveDepth)
	{
		ans = max(ans, curMax);
		limit[maxMoveDepth] = ans;
		for (int i = maxMoveDepth; i > 0; i--)
			limit[i - 1] = limit[i] / 2;
		return;
	}

	vvi boardOrigin = board;
	forn(r, n) forn(c, n) boardOrigin[r][c] = board[r][c];

	// 방향별 이동
	forn(dir, 4)
	{
		// 이 방향에서 움직여도 변화 없었으면 더 이상 x
		move(board, dir);
		if (false == isSame(board, boardOrigin))
		{
			dfs(board, depth + 1);
			forn(r, n) forn(c, n) board[r][c] = boardOrigin[r][c];
		}
	}
}

void solution() {
	cin >> n;
	vvi board(n, vi(n));

	for (int r = 0; r != n; r++)
	{
		for (int c = 0; c != n; c++)
		{
			cin >> board[r][c];
			ans = max(ans, board[r][c]);
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