#include <iostream>
#include <vector>

using namespace std;

int main()
{
	while (1)
	{
		int n;
		cin >> n;
		if (n == -1)
			return 0;

		vector<int> v;

		for (int i = 1; i < n; i++)
			if (n % i == 0)
				v.push_back(i);

		int sum = 0;

		for (auto& elem : v)
			sum += elem;

		if (sum != n)
			cout << n << " is NOT perfect.\n";
		else
		{
			cout << n << " = ";
			for (auto& elem : v)
			{
				cout << elem;
				if (elem != v.back())
					cout << " + ";
			}
			cout << '\n';
		}
	}

	return 0;
}