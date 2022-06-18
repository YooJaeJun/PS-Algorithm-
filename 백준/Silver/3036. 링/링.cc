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


void solution()
{
	int n;
	cin >> n;
	int r1;
	cin >> r1;
	forn(i, n - 1)
	{
		int r2;
		cin >> r2;
		
		int mod = 1;
		for (int i = 1; i <= r2; i++)
		{
			if (r1 % i == 0 and r2 % i == 0) mod = i;
		}
		cout << r1 / mod << '/' << r2 / mod << '\n';
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