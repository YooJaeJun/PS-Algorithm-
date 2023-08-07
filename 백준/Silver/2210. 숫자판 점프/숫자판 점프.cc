#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	constexpr int n = 5;
	vector<vector<int>> grid(n, vector<int>(n));
	for (int x = 0; x < n; x++)
		for (int y = 0; y < n; y++)
			cin >> grid[x][y];

	const int dx[4]{ 0,0,1,-1 };
	const int dy[4]{ 1,-1,0,0 };
	unordered_map<string, int> dic;

	function<void(string&, const int, const int, const int)> dfs =
		[&](string& cur, const int x, const int y, const int depth)
	{
		if (depth == n)
		{
			dic[cur] = 1;
			return;
		}

		for (int i=0; i<4; i++)
		{
			const int nx = x + dx[i];
			const int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;

			cur += '0' + grid[nx][ny];
			dfs(cur, nx, ny, depth + 1);
			cur.pop_back();
		}
	};

	string cur;

	for (int x=0; x<n; x++)
	{
		for (int y=0; y<n; y++)
		{
			cur.clear();
			cur += '0' + grid[x][y];
			dfs(cur, x, y, 0);
		}
	}

	cout << dic.size();

	return 0;
}