#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
#define yes cout << "YES\n";
#define no cout << "NO\n";
const int maxn = 100001;
const double mod = 1e9 + 7;


void solution()
{
	int n, k;
	cin >> n >> k;
	string s;
	vi oneIdxs;

	for (int i = 0; i < n; i++)
	{
		char ch;
		cin >> ch;
		s += ch;
		if (ch == '1') oneIdxs.push_back(i);
	}
	// 뒤부터
	if (k != 0 && oneIdxs.empty() == false)
	{
		int oneIdx = oneIdxs.back();
		if (s.size() - oneIdx - 1 <= k)
		{
			s[oneIdx] = '0';
			s[s.size() - 1] = '1';
			k -= (s.size() - oneIdx - 1);
		}
	}

	oneIdxs.clear();
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '1') oneIdxs.push_back(i);
	}
	// 앞
	if (k != 0 && oneIdxs.empty() == false)
	{
		int oneIdx = oneIdxs.front();
		if (oneIdx < s.size() - 1 && oneIdx <= k)
		{
			s[oneIdx] = '0';
			s[0] = '1';
			k -= oneIdx;
		}
	}
	
	int sum = s.size() == 1 ? s[0] - '0' : 0;
	for (int i = 0; i < (int)s.size() - 1; i++)
	{
		if (s[i] == '1' || s[i + 1] == '1')
		{
			sum += ((s[i] - '0') * 10 + s[i + 1] - '0');
		}
	}
	cout << sum << '\n';
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}