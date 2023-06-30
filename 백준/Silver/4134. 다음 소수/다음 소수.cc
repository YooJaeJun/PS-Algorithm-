#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	long long input;

	while (t--)
	{
		cin >> input;

		if (input <= 2)
		{
			cout << 2 << '\n';
			continue;
		}

		while (1)
		{
			bool loopBreak = false;

			for (long long j = 2; j * j <= input && !loopBreak; j++)
				if (input % j == 0)
					loopBreak = true;

			if (!loopBreak)
			{
				cout << input << '\n';
				break;
			}

			input++;
		}
	}

	return 0;
}