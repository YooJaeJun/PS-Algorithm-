#include <iostream>
#include <vector>
#include <functional>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	int cnt = 1;
	for (int i = 0; i < n; i++)
		cnt *= 2;
	cnt--;
	cout << cnt << '\n';

	function<void(int, int, int)> Hanoi = [&](int n, int s, int e)
	{
		auto Move = [&](int s, int e)
		{
			cout << s << ' ' << e << '\n';
		};

		if (n == 1)
		{
			Move(s, e);
			return;
		}

		int via = 6 - s - e;
		Hanoi(n - 1, s, via);
		Move(s, e);
		Hanoi(n - 1, via, e);
	};

	Hanoi(n, 1, 3);

	return 0;
}