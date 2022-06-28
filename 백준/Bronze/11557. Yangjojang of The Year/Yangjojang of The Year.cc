#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
#define forn(i, n) for (int i=0; i<(int)n; i++)
#define forn1(i, n) for (int i=1; i<=(int)n; i++)
#define yes cout << "YES\n";
#define no cout << "NO\n";
const int maxn = 1e9 + 7;
const double mod = 1e9 + 7;

struct info
{
	string s;
	int n;
};

void solution()
{
	int n;
	cin >> n;
	
	map<int, string> dic;
	forn(i, n)
	{
		string s;
		int l;
		cin >> s >> l;
		dic[l] = s;
	}
	auto it = --dic.end();
	cout << it->second << '\n';
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}