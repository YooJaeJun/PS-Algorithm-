#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string s;
	cin >> s;
	int q;
	cin >> q;
	char a;
	int l, r;
	unordered_map<char, vector<int>> dic;

	for (int i=0; i<s.size(); i++)
		dic[s[i]].emplace_back(i + 1);

	while (q--)
	{
		cin >> a >> l >> r;
		l++;
		r++;
		int cnt = 0;

		for (auto& elem : dic[a])
		{
			if (elem == 0)
				continue;

			if (elem >= l && elem <= r)
				cnt++;
		}

		cout << cnt << '\n';
	}

	return 0;
}