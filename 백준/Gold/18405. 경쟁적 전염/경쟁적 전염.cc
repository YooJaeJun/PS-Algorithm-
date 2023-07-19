#include <iostream>
#include <vector>
#include <deque>
#include <functional>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;
	vector<vector<int>> grid(n, vector<int>(n));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> grid[i][j];

	int s, x, y;
	cin >> s >> x >> y;

	int dr[4]{ 0,0,1,-1 };
	int dc[4]{ 1,-1,0,0 };
	deque<deque<bool>> visited(n, deque<bool>(n));

	auto IsValid = [&](int r, int c) ->bool
	{
		if (r < 0 || r >= n || c < 0 || c >= n)
			return false;
		if (0 == grid[r][c] || visited[r][c])
			return false;
		return true;
	};

	function<void(int, int, int)> Spread = [&](int idx, int r, int c)
	{
		int minn = 1e9;

		for (int i = 0; i < 4; i++)
		{
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (IsValid(nr, nc))
				minn = min(minn, grid[nr][nc]);
		}

		grid[r][c] = (minn == 1e9) ? 0 : minn;
		visited[r][c] = true;
	};

	while (s--)
	{
		for (int r = 0; r < n; r++)
			for (int c = 0; c < n; c++)
				if (0 == grid[r][c])
					Spread(grid[r][c], r, c);

		for (int r = 0; r < n; r++)
			fill(visited[r].begin(), visited[r].end(), false);
	}

	cout << grid[x - 1][y - 1];

	return 0;
}