#include <iostream>
#include <functional>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	using ll = long long;
	ll a, b, c;
	cin >> a >> b >> c;

	function<ll(const ll, const ll)> Pow = [&](const ll a, const ll b)
	{
		if (b == 1)
			return a % c;
		else if (b & 1)
			return Pow(a, b - 1) * a % c;

		const ll x = Pow(a, b / 2);
		return x % c * x % c;
	};
	cout << Pow(a, b);

	return 0;
}