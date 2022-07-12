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

enum eState { die, alive };
struct tagShark { int r, c, s, d, z, state = alive; };

void solution()
{
	int r, c, m;
	cin >> r >> c >> m;
	vector<tagShark> sharks(m);
	vvi grid(r, vi(c, -1));	// shark index

	forn(i, m)
	{
		cin >> sharks[i].r >> sharks[i].c >> sharks[i].s >> sharks[i].d >> sharks[i].z;
		sharks[i].r--;	sharks[i].c--;
		sharks[i].s =
			((sharks[i].d == 1 or sharks[i].d == 2) ?
				sharks[i].s % ((r - 1) * 2) :
				sharks[i].s % ((c - 1) * 2));
		grid[sharks[i].r][sharks[i].c] = i;
	}

	int ans = 0;
	int fisherPos = 0;

	while (fisherPos < c)
	{
		// 낚시
		forn(row, r)
		{
			int& sharkIdx = grid[row][fisherPos];
			if (sharkIdx != -1)
			{
				ans += sharks[sharkIdx].z;
				sharks[sharkIdx].state = die;
				sharkIdx = -1;
				break;
			}
		}
		// 상어
		int idx = 0;
		for (auto& shark : sharks)
		{
			if (shark.state == alive)
			{// 이동
				grid[shark.r][shark.c] = -1;

				if (shark.d == 1)
				{
					shark.r -= shark.s;
					if (shark.r < 0)
					{
						shark.r *= -1;
						shark.d = 2;
						if (shark.r >= r)	// 방향 한 번 더 바뀌는 경우
						{
							shark.r = (r - 1) - (shark.r - (r - 1));
							shark.d = 1;
						}
					}
				}
				else if (shark.d == 2)
				{
					shark.r += shark.s;
					if (shark.r >= r)
					{
						shark.r = (r - 1) - (shark.r - (r - 1));
						shark.d = 1;
						if (shark.r < 0)
						{
							shark.r *= -1;
							shark.d = 2;
						}
					}
				}
				else if (shark.d == 3)
				{
					shark.c += shark.s;
					if (shark.c >= c)
					{
						shark.c = (c - 1) - (shark.c - (c - 1));
						shark.d = 4;
						if (shark.c < 0)
						{
							shark.c *= -1;
							shark.d = 3;
						}
					}
				}
				else if (shark.d == 4)
				{
					shark.c -= shark.s;
					if (shark.c < 0)
					{
						shark.c *= -1;
						shark.d = 3;
						if (shark.c >= c)
						{
							shark.c = (c - 1) - (shark.c - (c - 1));
							shark.d = 4;
						}
					}
				}
			}
			idx++;
		}
		// 포식
		idx = 0;
		for (auto& shark : sharks)
		{
			if (shark.state == alive)
			{
				int& sharkIdx = grid[shark.r][shark.c];
				if (sharkIdx != -1)
				{
					if (sharks[sharkIdx].z > shark.z) shark.state = die;
					else
					{
						sharks[sharkIdx].state = die;
						sharkIdx = idx;
					}
				}
				else sharkIdx = idx;
			}
			idx++;
		}
		// cout << '\n'; forn(i, r) { forn(j, c) { cout << grid[i][j] << ' '; } cout << '\n'; } cout << '\n';
		fisherPos++;
	}

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