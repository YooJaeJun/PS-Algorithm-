#include <iostream>
#include <unordered_map>
#include <vector>
#include <deque>
#include <functional>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<string> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	unordered_map<string, int> dic;
	deque<bool> visited(n);

	function<void(const string&, const int)> BT = 
		[&](const string& cur, const int depth)
	{
		if (depth == k)
		{
			dic[cur] = 1;
			return;
		}

		for (int i = 0; i < n; i++)
		{
			if (visited[i])
				continue;
			visited[i] = true;
			string next = cur + v[i];
			BT(next, depth + 1);
			visited[i] = false;
		}
	};
	string cur;
	BT(cur, 0);

	cout << dic.size();
}