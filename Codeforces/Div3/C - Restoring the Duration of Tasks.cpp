#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
#define yes cout << "YES\n";
#define no cout << "NO\n";
const int maxn = 1e9 + 7;
const double mod = 1e9 + 7;


void solution()
{
	int n;
	cin >> n;
	vi s(n), f(n);
	for (int i = 0; i < n; ++i) cin >> s[i];
	for (int i = 0; i < n; ++i)
	{
		cin >> f[i];

		if (i == 0)
		{
			cout << f[i] - s[i] << ' ';
			continue;
		}

		cout << min(f[i] - s[i], f[i] - f[i - 1]) << ' ';
	}
	cout << '\n';
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}