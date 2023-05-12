#include <iostream>
#include <string>
#include <functional>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for (int i=1; i<=n; i++)
	{
		int temp = i;
		int sum = temp;
		while (temp != 0)
		{
			sum += temp % 10;
			temp /= 10;
		}
		if (sum == n)
		{
			cout << i;
			return 0;
		}
	}
	cout << 0;

	return 0;
}
