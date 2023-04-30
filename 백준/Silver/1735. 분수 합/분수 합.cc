#include <iostream>
#include <functional>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	using ll = long long;
	ll a, b, c, d;
	cin >> a >> b >> c >> d;

	a *= d;
	c *= b;

	ll numer = a + c;
	ll demo = b * d;

	function<ll(ll, ll)> Gcd = [&](const ll a, const ll b)
	{
		if (b == 0) return a;
		return Gcd(b, a % b);
	};

	ll gcd = Gcd(numer, demo);
	numer /= gcd;
	demo /= gcd;

	cout << numer << ' ' << demo;

	return 0;
}