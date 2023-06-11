#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	vector<pair<int, int>> vp(n);

	for (int i = 0; i < n; i++)
		cin >> vp[i].first >> vp[i].second;

	sort(vp.begin(), vp.end(), [](const pair<int, int> a, const pair<int, int> b)
	{
		if (a.first == b.first)
			return a.second < b.second;
		return a.first < b.first;
	});

	for (auto& elem : vp)
		cout << elem.first << ' ' << elem.second << '\n';

	return 0;
}
