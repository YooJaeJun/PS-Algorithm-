#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	vector<bool> prime(m + 1, true);

	auto CheckPrime = [&]()
	{
		prime[0] = prime[1] = false;

		int limit = sqrt(m);
		for (int i = 2; i <= m; i++)
		{
			if (prime[i] == false)
				continue;
			
			for (int j = 2; i * j <= m; j++)
			{
				prime[i * j] = false;
			}
		}
	};

	CheckPrime();

	int minn = 1e9, sum = 0;

	for (int i = n; i <= m; i++)
	{
		if (prime[i])
		{
			minn = min(minn, i);
			sum += i;
		}
	}

	if (minn == 1e9)
		cout << -1;
	else
		cout << sum << '\n' << minn;

	return 0;
}