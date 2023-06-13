#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> coins(n);
	for (int i = 0; i < n; i++)
		cin >> coins[i];

	sort(coins.begin(), coins.end(), greater<int>());
	int cur = k, ans = 0;

	for (auto& elem : coins)
	{
		if (elem > cur)
			continue;

		ans += cur / elem;
		cur %= elem;
	}

	cout << ans;

	return 0;
}
