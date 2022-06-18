#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using db = deque<bool>;
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define forn(i, n) for (int i = 0; i < (int)n; i++)
const int maxn = 1e9;
const double mod = 1e9 + 7;

int memo[200'000][26];

void solution()
{
	string s;
	cin >> s;
	
	int q;
	cin >> q;

	map<int, int> dic;
	forn(i, s.size())
	{
		dic[s[i] - 'a']++;
		for (auto& elem : dic)
		{
			memo[i][elem.first] = elem.second;
		}
	}

	char ch;
	int l, r;
	forn(i, q)
	{
		cin >> ch >> l >> r;
		if (l == 0) cout << memo[r][ch - 'a'] << '\n';
		else cout << memo[r][ch - 'a'] - memo[l - 1][ch - 'a'] << '\n';
	}
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}