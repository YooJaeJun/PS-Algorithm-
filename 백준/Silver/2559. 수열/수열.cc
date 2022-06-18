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
	int n, k;
	cin >> n >> k;
	vi psum(n);
	forn(i, n)
	{
		int num;
		cin >> num;
		if (i == 0) psum[i] = num;
		else psum[i] = num + psum[i - 1];
	}

	k--;
	int ans = psum[k];
	for (int i = 1; i < n - k; i++)
	{
		ans = max(ans, psum[i + k] - psum[i - 1]);
	}
	cout << ans;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}