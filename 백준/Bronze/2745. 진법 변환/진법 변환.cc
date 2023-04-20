#include <iostream>
using namespace std;

int main()
{
	string n;
	int b;
	cin >> n >> b;
	int ans = 0, cur = 1;

	for (int i = n.size() - 1; i >= 0; i--)
	{
		if (n[i] >= '0' && n[i] <= '9')
			ans += (n[i] - '0') * cur;
		else
			ans += (n[i] - 'A' + 10) * cur;
		
		cur *= b;
	}
	cout << ans;
}