#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

vector<vector<pair<int, int>>> tet {
	// |
	{ { 0, 0 }, { 0, 1 }, { 0, 2 }, { 0, 3 }},
	{ { 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 }},

	// ㅁ   
	{ { 0, 0 }, { 0, 1 }, { 1, 0 }, { 1, 1 } },

	// L    
	{ { 0, 0 }, { 1, 0 }, { 2, 0 }, { 2, 1 } },
	{ { 1, 0 }, { 1, 1 }, { 1, 2 }, { 0, 2 } },
	{ { 0, 0 }, { 0, 1 }, { 1, 1 }, { 2, 1 } },
	{ { 0, 0 }, { 0, 1 }, { 0, 2 }, { 1, 0 } },

	{ { 2, 0 }, { 2, 1 }, { 1, 1 }, { 0, 1 } },
	{ { 0, 0 }, { 0, 1 }, { 0, 2 }, { 1, 2 } },
	{ { 0, 0 }, { 0, 1 }, { 1, 0 }, { 2, 0 } },
	{ { 0, 0 }, { 1, 0 }, { 1, 1 }, { 1, 2 } },

	// 번개
	{ { 0, 0 }, { 1, 0 }, { 1, 1 }, { 2, 1 } },
	{ { 1, 0 }, { 1, 1 }, { 0, 1 }, { 0, 2 } },
	{ { 0, 1 }, { 1, 0 }, { 1, 1 }, { 2, 0 } },
	{ { 0, 0 }, { 0, 1 }, { 1, 1 }, { 1, 2 } },

	// ㅗ
	{ { 0, 0 }, { 0, 1 }, { 0, 2 }, { 1, 1 } },
	{ { 0, 1 }, { 1, 0 }, { 1, 1 }, { 1, 2 } },
	{ { 0, 0 }, { 1, 0 }, { 1, 1 }, { 2, 0 } },
	{ { 0, 1 }, { 1, 0 }, { 1, 1 }, { 2, 1 } },
};

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> grid(n, vector<int>(m));

	for (int x = 0; x < n; x++)
		for (int y = 0; y < m; y++)
			cin >> grid[x][y];

	int ans = 0, r = tet.size(), c = 4;

	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < m; y++)
		{
			for (int i = 0; i < r; i++)
			{
				int sum = 0;

				for (int j = 0; j < c; j++)
				{
					int nx = x + tet[i][j].first;
					int ny = y + tet[i][j].second;

					if (nx < 0 || nx >= n || ny < 0 || ny >= m)
						continue;

					sum += grid[nx][ny];
				}

				ans = max(ans, sum);
			}
		}
	}

	cout << ans;

	return 0;
}