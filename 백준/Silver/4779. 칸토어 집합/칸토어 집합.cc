#include <iostream>
#include <vector>
#include <functional>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	vector<int> v;
	int tmp = 1;
	for (int i=0; i<=12; i++)
	{
		v.emplace_back(tmp);
		tmp *= 3;
	}

	while (cin >> n)
	{
		string str;
		str.resize(v[n] + 1, ' ');

		function<void(int, int)> Divide = [&](int size, int start)
		{
			if (size == 0)
			{
				str[start] = '-';
				return;
			}

			Divide(size / 3, start);
			Divide(size / 3, start + 2 * size / 3);
		};
		Divide(v[n], 1);

		for (int i = 1; i < str.size(); i++)
			cout << str[i];
		cout << '\n';
	}

	return 0;
}