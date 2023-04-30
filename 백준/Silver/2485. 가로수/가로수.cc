#include <iostream>
#include <vector>
#include <functional>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	function<int(const int, const int)> Gcd = [&](const int a, const int b)
	{
		if (b == 0) return a;
		return Gcd(b, a % b);
	};

	vector<int> v(n);
	int prev = -1, input = 0, gcd = -1;

	cin >> input;
	v[0] = prev = input;

	for (int i=1; i<n; i++)
	{
		cin >> input;
		v[i] = input;
		if (i == 1)
			gcd = input - prev;
		else 
			gcd = Gcd(gcd, input - prev);
		prev = input;
	}

	int ans = 0;

	for (int i=1; i<n; i++)
		ans += (v[i] - v[i - 1]) / gcd - 1;

	cout << ans;

	return 0;
}