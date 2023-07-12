#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, c;
	cin >> n >> c;
	vector<int> house(n);

	for (int i = 0; i < n; i++)
		cin >> house[i];

	sort(house.begin(), house.end());

	int start = 1;
	int end = house[n - 1] - house[0];
	int mid, router, cur, ans = 0;

	while (start <= end)
	{
		router = 1;
		mid = (start + end) / 2;
		cur = house[0];

		for (int i=1; i<n; i++)
		{
			if (house[i] - cur >= mid)
			{
				router++;
				cur = house[i];
			}
		}

		if (router >= c)
		{
			ans = max(ans, mid);
			start = mid + 1;
		}
		else
			end = mid - 1;
	}

	cout << ans;

	return 0;
}