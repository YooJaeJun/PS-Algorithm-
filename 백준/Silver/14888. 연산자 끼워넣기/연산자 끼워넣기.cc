#include <iostream>
#include <array>
#include <vector>
#include <functional>

using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	int oper[4] = { 0, };
	for (int i = 0; i < 4; i++)
		cin >> oper[i];

	int maxn = -1e9, minn = 1e9;

	function<void(int, int)> BackTracking = [&](int res, int index)
	{
		if (index == v.size())
		{
			maxn = max(maxn, res);
			minn = min(minn, res);
			return;
		}

		for (int i=0; i<4; i++)
		{
			if (oper[i] <= 0)
				continue;

			oper[i]--;

			switch (i)
			{
			case 0:
				BackTracking(res + v[index], index + 1);
				break;
			case 1:
				BackTracking(res - v[index], index + 1);
				break;
			case 2:
				BackTracking(res * v[index], index + 1);
				break;
			case 3:
				BackTracking(res / v[index], index + 1);
				break;
			}

			oper[i]++;
		}
	};
	BackTracking(v[0], 1);

	cout << maxn << '\n' << minn;

	return 0;
}