#include <iostream>
#include <functional>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;

	while (t--)
	{
		int a, b;
		cin >> a >> b;

		function<int(int, int)> Gcd = [&](int a, int b)
		{
			if (b == 0) return a;
			return Gcd(b, a % b);
		};

		auto Lcm = [&](int a, int b)
		{
			return a * b / Gcd(a, b);
		};

		cout << Lcm(a, b) << '\n';
	}
}