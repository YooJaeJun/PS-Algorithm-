#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int cur = 1, coef = 2, sum = 6, ans = 1;

	while (cur < n)
	{
		cur += sum;
		sum = 6 * coef;
		coef++;
		ans++;
	}
	cout << ans;
}