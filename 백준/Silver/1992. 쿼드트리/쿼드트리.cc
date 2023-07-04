#include <iostream>
#include <deque>
#include <functional>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	vector<vector<char>> grid(n, vector<char>(n));
	for (int x = 0; x < n; x++)
		for (int y = 0; y < n; y++)
			cin >> grid[x][y];

	function<void(int, int, int)> DivideConquer = [&](int size, int x, int y)
	{
		if (size == 1)
		{
			cout << grid[x][y];
			return;
		}

		bool loopBreak = false;

		for (int r=x; r<x+size && !loopBreak; r++)
			for (int c=y; c<y+size && !loopBreak; c++)
				if (grid[x][y] != grid[r][c])
					loopBreak = true;

		if (loopBreak)
		{
			cout << "(";
			DivideConquer(size / 2, x, y);
			DivideConquer(size / 2, x, y + size / 2);
			DivideConquer(size / 2, x + size / 2, y);
			DivideConquer(size / 2, x + size / 2, y + size / 2);
			cout << ")";
		}
		else
			cout << grid[x][y];
	};

	DivideConquer(n, 0, 0);

	return 0;
}