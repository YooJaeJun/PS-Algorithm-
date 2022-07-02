#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using db = deque<bool>;
using ddb = deque<deque<bool>>;
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define forn1(i, n) for (int i = 1; i <= (int)n; i++)
const int maxn = 1e9 + 7;
const double mod = 1e9 + 7;

struct coord { int x, y; };

struct unit
{
	coord pos;
	int dir;
	int score;
	bool life = true;
};

// 안씀, ↑, ↖, ←, ↙, ↓, ↘, →, ↗
int dx[9] = { -99, -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[9] = { -99, 0, -1, -1, -1, 0, 1, 1, 1 };

enum location
{
	emptyin = 0, sharkin = -1
};

bool isOut(int x, int y, int n)
{
	return (x <= 0 || x > n || y <= 0 || y > n);
}

void solution()
{
	const int n = 4;
	vvi grid(n + 1, vi(n + 1));		// 0, -1 제외한 수: fish index
	vector<unit> fishes(n * n + 1);

	forn1(x, n)
	{
		forn1(y, n)
		{
			int idx, dir;
			cin >> idx >> dir;
			fishes[idx] = { {x,y}, dir, 0, true };
			grid[x][y] = idx;
		}
	}

	// 이하 이벤트 발생할 때마다 shark, fish, grid 모두 바꿔주어야 함

	unit shark{ {1, 1}, fishes[grid[1][1]].dir, grid[1][1] };
	int ans = shark.score;

	int& fishInitIdx = grid[1][1];
	fishes[fishInitIdx].life = false;
	fishInitIdx = sharkin;

	// vector<string> vs = { "", "↑", "↖", "←", "↙", "↓", "↘", "→", "↗" };

	function<void(vvi, unit, vector<unit>)> simulation =
		[&](vvi grid, unit shark, vector<unit> fishes)
	{
		// fish turn
		for (auto& fish : fishes)
		{
			int& fishIdx = grid[fish.pos.x][fish.pos.y];

			if (fishIdx == sharkin or fishIdx == emptyin) continue;

			int maxMoveCnt = 7;
			while (maxMoveCnt--)
			{
				int nx = fish.pos.x + dx[fish.dir];
				int ny = fish.pos.y + dy[fish.dir];

				if (isOut(nx, ny, n) ||
					grid[nx][ny] == sharkin)
				{
					fish.dir = (fish.dir + 1) % 9;
					if (fish.dir == 0) fish.dir++;
				}
				else if (fish.life)
				{
					int& newIdx = grid[nx][ny];
					int& curIdx = grid[fish.pos.x][fish.pos.y];

					if (newIdx != 0) fishes[newIdx].pos = fish.pos;	// empty 였을 경우 fish 는 스왑하지 않음
					swap(newIdx, curIdx);	// grid에서 요소(= fish나 empty의 index) 스왑
					fish.pos = { nx, ny };

					// forn1(x, n) { forn1(y, n) { cout << grid[x][y] << "(" << (grid[x][y] == -1 ? vs[shark.dir] : vs[fishes[grid[x][y]].dir]) << ")" << ' '; } cout << '\n'; } cout << shark.score << "\n\n";
					break;
				}
			}
		}
		// forn1(x, n) { forn1(y, n) { cout << grid[x][y] << "(" << (grid[x][y] == -1 ? vs[shark.dir] : vs[fishes[grid[x][y]].dir]) << ")" << ' '; } cout << '\n'; } cout << shark.score << "\n\n";

		// 백트래킹 저장용
		vvi gridCopy = grid;
		unit sharkCopy = shark;
		vector<unit> fishesCopy = fishes;

		// shark turn
		for (int i = 1; i <= 3; i++)
		{
			int nx = shark.pos.x + dx[shark.dir] * i;
			int ny = shark.pos.y + dy[shark.dir] * i;

			if (isOut(nx, ny, n)) break;

			int& newSharkIdx = grid[nx][ny];
			if (newSharkIdx == emptyin) continue;

			// 잡아먹기
			int& curSharkIdx = grid[shark.pos.x][shark.pos.y];
			curSharkIdx = emptyin;
			fishes[newSharkIdx].life = false;
			shark = { {nx, ny}, fishes[newSharkIdx].dir, shark.score + newSharkIdx };
			newSharkIdx = sharkin;
			ans = max(ans, shark.score);

			// forn1(x, n) { forn1(y, n) { cout << grid[x][y] << "(" << (grid[x][y] == -1 ? vs[shark.dir] : vs[fishes[grid[x][y]].dir]) << ")" << ' '; } cout << '\n'; } cout << shark.score << "\n\n";

			simulation(grid, shark, fishes);

			// 회귀
			grid = gridCopy;
			shark = sharkCopy;
			fishes = fishesCopy;
			fishes[newSharkIdx].life = true;
		}
	};
	// forn1(x, n) { forn1(y, n) { cout << grid[x][y] << "(" << (grid[x][y] == -1 ? vs[shark.dir] : vs[fishes[grid[x][y]].dir]) << ")" << ' '; } cout << '\n'; } cout << shark.score << "\n\n";
	simulation(grid, shark, fishes);

	cout << ans;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}