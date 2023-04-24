#include <iostream>

using namespace std;

int main()
{
	enum { factor = 0, multiple = 1, neither = 2 };
	string ans[3] = { "factor", "multiple", "neither" };

	int a = 0, b = 0;

	while (cin >> a >> b)
	{
		if (a == 0 && b == 0)
			break;

		if (a < b && b % a == 0)
			cout << ans[factor] << '\n';
		else if (b < a && a % b == 0)
			cout << ans[multiple] << '\n';
		else
			cout << ans[neither] << '\n';
	}

	return 0;
}