#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int c;
	cin >> c;
	vector<int> v;

	cout << fixed;
	cout.precision(3);

	while (c--)
	{
		int n;
		cin >> n;
		v.resize(n);
		float sum = 0;

		for (int i=0; i<n; i++)
		{
			cin >> v[i];
			sum += (float)v[i];
		}

		int average = sum / (float)n;
		float cnt = 0;

		for (int i=0; i<n; i++)
			if (average < v[i])
				cnt++;

		cout << cnt / n * 100.0f << "%" << '\n';
	}

	return 0;
}