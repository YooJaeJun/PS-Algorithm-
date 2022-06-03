#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
#define yes cout << "YES\n";
#define no cout << "NO\n";
const int maxn = 100001;
const double mod = 1e9 + 7;

struct Coord
{
	int x, y;
};

enum class info
{
	space, snake, apple	// 0:빈곳, 1:뱀, 2:사과
};

struct Command
{
	int time;
	char dir;
};

enum class dir
{
	right, down, left, up
};
int dx[4] = { 0,1,0,-1 };	// x가 행
int dy[4] = { 1,0,-1,0 };

struct Snake
{
	deque<Coord> body;
};

void solution()
{
	int n, k;
	cin >> n >> k;
	vvi grid(n, vi(n));
	for (int i = 0; i < k; i++)
	{
		int r, c;
		cin >> r >> c;
		grid[r - 1][c - 1] = (int)info::apple;
	}

	Snake snake;
	snake.body.push_front({ 0, 0 });
	grid[0][0] = (int)info::snake;

	int l;
	cin >> l;
	vector<Command> command(l);
	for (int i = 0; i < l; i++) cin >> command[i].time >> command[i].dir;

	int dir = (int)dir::right;
	int cIdx = 0;
	Coord head{0, 0};
	Coord tail{0, 0};

	for (int t = 1; ; t++)
	{
		if (cIdx <= command.size() - 1 and t == command[cIdx].time + 1)
		{
			// 방향회전
			if (command[cIdx].dir == 'D')
			{
				++dir;
				if (dir > (int)dir::up) dir = (int)dir::right;
			}
			else
			{
				--dir;
				if (dir < (int)dir::right) dir = (int)dir::up;
			}
			++cIdx;
		}

		int nx = snake.body.front().x + dx[dir];
		int ny = snake.body.front().y + dy[dir];

		if (nx < 0 || nx >= n || ny < 0 || ny >= n)
		{
			cout << t;
			return;
		}
		// 이동
		snake.body.push_front({ nx, ny });
		head = { snake.body.front().x, snake.body.front().y};
		tail = { snake.body.back().x, snake.body.back().y};

		if (grid[head.x][head.y] == (int)info::space)
		{
			grid[tail.x][tail.y] = (int)info::space;
			snake.body.pop_back();
		}
		else if (grid[head.x][head.y] == (int)info::snake)
		{
			cout << t;
			return;
		}
		grid[head.x][head.y] = (int)info::snake;
	}
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}