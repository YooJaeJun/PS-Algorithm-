#include <bits/stdc++.h>
#include <unordered_map>
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
const int maxn = 1e9 + 7;
const double mod = 1e9 + 7;


void solution()
{
	int n;
	cin >> n;
	unordered_map<int, int> a;
	forn(i, n)
	{
		int num;
		cin >> num;
		a[num] = 1;
	}

	int m;
	cin >> m;
	forn(i, m)
	{
		int num;
		cin >> num;
		if (a[num]) cout << 1 << '\n';
		else cout << 0 << '\n';
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