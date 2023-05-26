#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		int r;
		cin >> r;
		string s;
		cin >> s;

		for (auto ch : s)
			for (int i = 0; i < r; i++)
				cout << ch;

		cout << '\n';
	}

	return 0;
}