#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;

	queue<int> q;
	for (int i = 1; i <= n; i++)
		q.push(i);

	cout << '<';

	while (false == q.empty())
	{
		for (int i = 0; i < k - 1; i++)
		{
			q.push(q.front());
			q.pop();
		}

		cout << q.front();
		cout << ((q.size() == 1) ? "" : ", ");
		
		q.pop();
	}

	cout << '>';

	return 0;
}
