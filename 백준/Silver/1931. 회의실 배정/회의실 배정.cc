#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	vector<pair<int, int>> v(n);

	for (int i=0; i<n; i++)
		cin >> v[i].first >> v[i].second;

	sort(v.begin(), v.end(), [](pair<int, int> p1, pair<int, int> p2)
	{
		if (p1.second == p2.second)
			return p1.first < p2.first;
		return p1.second < p2.second;
	});

	int endTime = 0, ans = 0;

	for (int i=0; i<n; i++)
	{
		if (endTime <= v[i].first)
		{
			endTime = v[i].second;
			ans++;
		}
	}

	cout << ans;
	
	return 0;
}