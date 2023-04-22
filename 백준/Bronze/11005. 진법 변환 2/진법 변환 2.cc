#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int n, b;
	cin >> n >> b;
	string ans;

	auto SumStr = [&](int cur)
	{
		if (cur >= 10)
			ans += 'A' + cur - 10;
		else
			ans += to_string(cur);
	};
	
	while (n >= b)
	{
		int cur = n % b;
		SumStr(cur);
		n /= b;
	}

	SumStr(n);

	while (ans.back() == '0')
		ans.pop_back();

	reverse(ans.begin(), ans.end());

	cout << ans;
}