#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	string input;
	unordered_map<string, int> dic;
	vector<string> v;

	for (int i=0; i<n; i++)
	{
		cin >> input;

		if (input.size() < m)
			continue;

		if (dic[input] == 0)
			v.emplace_back(input);

		dic[input]++;
	}

	sort(v.begin(), v.end(), [&](const string& s1, const string& s2)
		{
			if (dic[s1] == dic[s2])
			{
				if (s1.size() == s2.size())
					return s1 < s2;

				return s1.size() > s2.size();
			}
			return dic[s1] > dic[s2];
		});

	for (auto& elem : v)
		cout << elem << '\n';

	return 0;
}