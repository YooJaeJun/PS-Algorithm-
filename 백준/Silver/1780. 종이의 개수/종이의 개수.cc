#include <iostream>
#include <deque>
#include <functional>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	vector<vector<int>> grid(n, vector<int>(n));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> grid[i][j];

	vector<int> ans(3);

	function<void(int, int, int)> DivideConquer = [&](int size, int x, int y)
	{
		if (size == 1)
		{
			ans[grid[x][y] + 1]++;
			return;
		}

		bool loopBreak = false;

		for (int r = x; r < x + size && !loopBreak; r++)
			for (int c = y; c < y + size && !loopBreak; c++)
				if (grid[r][c] != grid[x][y])
					loopBreak = true;

		if (loopBreak)
		{
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					DivideConquer(size / 3, 
						x + size / 3 * i, 
						y + size / 3 * j);
		}
		else
			ans[grid[x][y] + 1]++;
	};
	DivideConquer(n, 0, 0);

	for (auto& elem : ans)
		cout << elem << '\n';

	return 0;
}