#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using db = deque<bool>;
using ddb = deque<deque<bool>>;
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define forn1(i, n) for (int i = 1; i <= (int)n; i++)
const int maxn = 1e9 + 7;
const double mod = 1e9 + 7;


void solution()
{
	int n, m;
	cin >> m >> n;
	vi psum(n);
	map<int, int> dic;
	forn(i, n)
	{
		int num;
		cin >> num;
		psum[i] += num;
		if (i - 1 >= 0) psum[i] += psum[i - 1];
		psum[i] %= m;
		dic[psum[i]]++;
	}

	int ans = dic[0];
	for (auto& elem : dic)
	{
		ans += elem.second * (elem.second - 1) / 2;
	}
	cout << ans << '\n';
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}