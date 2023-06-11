#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	vector<string> vs(n);

	for (int i = 0; i < n; i++)
		cin >> vs[i];

	sort(vs.begin(), vs.end(), [](const string& a, const string& b)
	{
		if (a.size() == b.size())
			return a < b;
		return a.size() < b.size();
	});

	vs.erase(unique(vs.begin(), vs.end()), vs.end());

	for (const auto& elem : vs)
		cout << elem << '\n';

	return 0;
}
