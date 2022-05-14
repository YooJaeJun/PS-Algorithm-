#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vc = vector<char>;
using vvc = vector<vector<char>>;

int l, c;
vc arr;

void bt(vc& v, int idx)
{
	if (v.size() == l)
	{
		int consonant = 0, vowel = 0;
		for (auto& elem : v)
		{
			if (elem == 'a' || elem == 'e' || elem == 'i' || elem == 'o' || elem == 'u') vowel++;
			else consonant++;
		}
		if (vowel >= 1 && consonant >= 2)
		{
			for (auto& elem : v)
			{
				cout << elem;
			}
			cout << '\n';
		}
		return;
	}

	for (int i = idx; i < c; ++i)
	{
		v.push_back(arr[i]);
		bt(v, i + 1);
		v.pop_back();
	}
}

void solution()
{
	cin >> l >> c;
	arr = vc(c);
	for (int i = 0; i < c; ++i)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());

	vc v;
	bt(v, 0);
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}