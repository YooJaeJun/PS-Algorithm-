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

struct tagCctv 
{ 
	int r, c, kind; 
};
int n, m;
int ans = maxn;
vvi grid(n, vi(m));
vector<tagCctv> cctv;
int cctvNum, wallNum;
vi dir;
// 동남서북: 나머지연산하기 좋게
const int dr[4] = { 0,1,0,-1 };
const int dc[4] = { 1,0,-1,0 };
ddb visited;

bool checkGrid(const int r, const int c)
{
	return false == ((r < 0 or r >= n or c < 0 or c >= m) or grid[r][c] == 6/*wall*/);
}

void checkCnt(int& cnt, int nr, int nc, const int direction)
{
	while (1)
	{
		nr += dr[direction];
		nc += dc[direction];
		if (checkGrid(nr, nc))
		{
			if (visited[nr][nc] == false and
				grid[nr][nc] == 0)
			{
				visited[nr][nc] = true;
				cnt++;
			}
		}
		else break;
	}
}

void checkArea(const int i, int& cnt)
{
	const int& kind = cctv[i].kind;
	int nr = cctv[i].r, nc = cctv[i].c;
	// 동남서북
	switch (kind)
	{
	case 1:
		checkCnt(cnt, nr, nc, dir[i]);
		break;

	case 2:
		checkCnt(cnt, nr, nc, dir[i]);
		checkCnt(cnt, nr, nc, (dir[i] + 2) % 4);
		break;

	case 3:
		checkCnt(cnt, nr, nc, dir[i]);
		checkCnt(cnt, nr, nc, (dir[i] + 1) % 4);
		break;

	case 4:
		checkCnt(cnt, nr, nc, dir[i]);
		checkCnt(cnt, nr, nc, (dir[i] + 1) % 4);
		checkCnt(cnt, nr, nc, (dir[i] + 2) % 4);
		break;

	case 5:
		checkCnt(cnt, nr, nc, dir[i]);
		checkCnt(cnt, nr, nc, (dir[i] + 1) % 4);
		checkCnt(cnt, nr, nc, (dir[i] + 2) % 4);
		checkCnt(cnt, nr, nc, (dir[i] + 3) % 4);
		break;
	}
}

void recur(int cur)
{
	if (cur == cctvNum)
	{
		for (auto& elem : visited) fill(elem.begin(), elem.end(), false);
		int cnt = 0;
		forn(i, cctvNum) checkArea(i, cnt);	// 영역체크
		ans = min(ans, n * m - cnt - cctvNum - wallNum);
		return;
	}

	const int kind = cctv[cur].kind;
	int dirIdx = 0;
	// 1-4번, 2-2번, 3-4번, 4-4번, 5-1번
	dirIdx = (kind == 1 or kind == 3 or kind == 4 ? 4 : kind == 2 ? 2 : 1);

	forn(i, dirIdx)
	{
		int temp = dir[cur];
		dir[cur] = i;
		recur(cur + 1);
		dir[cur] = temp;
	}
}

void solution()
{
	cin >> n >> m;
	grid = vvi(n, vi(m));
	visited = ddb(n, db(m));
	forn(r, n)
	{
		forn(c, m)
		{
			cin >> grid[r][c];
			const int cur = grid[r][c];
			if (cur >= 1 and cur <= 5)
				cctv.push_back({ r, c, cur });
			else if (cur == 6)
				wallNum++;
		}
	}
	cctvNum = cctv.size();
	dir.resize(cctvNum);

	recur(0);

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