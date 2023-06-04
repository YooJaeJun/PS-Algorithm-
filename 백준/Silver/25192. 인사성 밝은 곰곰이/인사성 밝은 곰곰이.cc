#include <iostream>
#include <map>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	string input;
	map<string, int> dic;
	int ans = 0;

	while (t--)
	{
		cin >> input;
		if (input == "ENTER")
			dic.clear();
		else if (0 == dic[input])
		{
			ans++;
			dic[input] = 1;
		}
	}

	cout << ans;

	return 0;
}