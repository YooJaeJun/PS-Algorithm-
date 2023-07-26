#include <iostream>
#include <vector>
#include <deque>
#include <queue>
using namespace std;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, l, r;
	cin >> n >> l >> r;
	vector<vector<int>> grid(n, vector<int>(n));

	for (int x=0; x<n; x++)
		for (int y=0; y<n; y++)
			cin >> grid[x][y];

	const int dx[4]{ 0,0,1,-1 };
	const int dy[4]{ 1,-1,0,0 };
	deque<deque<bool>> visited(n, deque<bool>(n));
	vector<pair<int, int>> candidate;
	int ans = 0, sum = 0;
	bool loopBreak = false;


	auto Bfs = [&](int i, int j)
	{
		queue<pair<int, int>> q;
		q.emplace(i, j);

		while (false == q.empty())
		{
			const int x = q.front().first;
			const int y = q.front().second;
			q.pop();

			for (int k = 0; k < 4; k++)
			{
				const int nx = x + dx[k];
				const int ny = y + dy[k];

				if (nx < 0 || nx >= n || ny < 0 || ny >= n)
					continue;

				if (visited[nx][ny])
					continue;

				const int diff = abs(grid[nx][ny] - grid[x][y]);

				if (diff >= l && diff <= r)
				{
					loopBreak = false;
					visited[nx][ny] = true;
					sum += grid[nx][ny];
					q.emplace(nx, ny);
					candidate.emplace_back(nx, ny);
				}
			}
		}
	};


	while (true)
	{
		loopBreak = true;
		candidate.clear();

		for (auto& elem : visited)
			fill(elem.begin(), elem.end(), false);

		for (int x = 0; x < n; x++)
		{
			for (int y = 0; y < n; y++)
			{
				if (visited[x][y])
					continue;

				sum = grid[x][y];
				visited[x][y] = true;
				candidate.clear();
				candidate.emplace_back(x, y);

				Bfs(x, y);

				const int average = sum / candidate.size();

				for (const auto& elem : candidate)
					grid[elem.first][elem.second] = average;
			}
		}

		if (loopBreak)
			break;

		ans++;

		//cout << '\n';
		//for (int x = 0; x < n; x++)
		//{
		//	for (int y = 0; y < n; y++)
		//		cout << grid[x][y] << ' ';

		//	cout << '\n';
		//}
		//cout << '\n';
	}

	cout << ans;

	return 0;
}