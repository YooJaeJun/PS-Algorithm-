#include <iostream>
#include <vector>
#include <deque>
#include <functional>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	deque<bool> visited(n + 1);

	function<void(vector<int>&, int)> BackTracking = [&](vector<int>& cur, int depth)
	{
		if (depth == m)
		{
			for (auto& elem : cur)
				cout << elem << ' ';
			cout << '\n';
			return;
		}

		for (int i=0; i<n; i++)
		{
			if (visited[i])
				continue;
			visited[i] = true;
			cur.emplace_back(i + 1);
			BackTracking(cur, depth + 1);
			cur.pop_back();
			visited[i] = false;
		}
	};
	vector<int> cur;
	BackTracking(cur, 0);

	return 0;
}
