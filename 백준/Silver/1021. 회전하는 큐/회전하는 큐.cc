#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	deque<int> dq;

	for (int i = 1; i <= n; i++)
		dq.emplace_back(i);

	vector<int> quest(m);

	for (int i = 0; i < m; i++)
		cin >> quest[i];

	int ans = 0;

	for (int i=0; i<m; i++)
	{
		auto it = find(dq.begin(), dq.end(), quest[i]);

		if (it - dq.begin() <= dq.end() - it)
		{
			int count = it - dq.begin();
			ans += count;

			for (int j=0; j<count; j++)
			{
				dq.emplace_back(dq.front());
				dq.pop_front();
			}

			dq.pop_front();
		}
		else
		{
			int count = dq.end() - it;
			ans += count;

			for (int j=0; j<count; j++)
			{
				dq.emplace_front(dq.back());
				dq.pop_back();
			}

			dq.pop_front();
		}
	}

	cout << ans;

	return 0;
}