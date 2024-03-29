#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;

	while (t--)
	{
		int n, m;
		cin >> n >> m;
		long long ans = 1;

		for (int i = 0; i < n; i++)
		{
			ans *= m - i;
			ans /= i + 1;
		}

		cout << ans << '\n';
	}

	return 0;
}