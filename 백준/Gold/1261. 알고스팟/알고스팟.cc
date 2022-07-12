#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vvvi = vector<vector<vector<int>>>;
using db = deque<bool>;
using ddb = deque<deque<bool>>;
using dddb = deque<deque<deque<bool>>>;
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define forn1(i, n) for (int i = 1; i <= (int)n; i++)
const int maxn = 1e9 + 7;
const double mod = 1e9 + 7;

struct coord 
{ 
	int x, y, breaking;
};

void solution()
{
	int n, m;
	cin >> m >> n;
	vector<string> grid(n);
	forn(i, n) cin >> grid[i];
	vvi memo(n, vi(m, maxn));
	int ans = maxn;

	auto bfs = [&]()
	{
		int dx[4] = { 0,0,1,-1 };
		int dy[4] = { 1,-1,0,0 };

		deque<coord> dq;
		dq.push_back({ 0,0,0 });
		memo[0][0] = 0;

		while (dq.empty() == false)
		{
			int x = dq.front().x;
			int y = dq.front().y;
			int breaking = dq.front().breaking;
			dq.pop_front();

			if (x == n - 1 and y == m - 1)
			{
				ans = min(ans, breaking);
				continue;
			}

			forn(i, 4)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

				int newBreaking = breaking;
				if (grid[nx][ny] == '1') newBreaking++;

				if (memo[nx][ny] <= newBreaking) continue;
				memo[nx][ny] = newBreaking;

				if (grid[nx][ny] == '1') dq.push_back({ nx, ny, newBreaking });
				else dq.push_front({ nx, ny, newBreaking });
			}
		}
	};
	bfs();

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