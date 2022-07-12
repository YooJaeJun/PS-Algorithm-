#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using db = deque<bool>;
using ddb = deque<deque<bool>>;
#define forn(i, n) for (int i=0; i<(int)n; i++)
#define forn1(i, n) for (int i=1; i<=(int)n; i++)
#define yes cout << "YES\n";
#define no cout << "NO\n";
const int maxn = 1e9 + 7;
const double mod = 1e9 + 7;


void solution()
{
	// 2x5 중 5의 개수만 알면.. => 5, 25, 125,..의 개수
	int n, m;
	cin >> n >> m;
	int ans5 = 0;
	const int five = 5;
	for (int i = five; i <= n; i *= five)
		ans5 += n / i;

	for (int i = five; i <= m; i *= five)
		ans5 -= m / i;

	for (int i = five; i <= n - m; i *= five)
		ans5 -= ((n - m) / i);

	int ans2 = 0;
	const int two = 2;
	for (int i = two; i <= n; i *= two)
		ans2 += n / i;

	for (int i = two; i <= m; i *= two)
		ans2 -= m / i;

	for (int i = two; i <= n - m; i *= two)
		ans2 -= ((n - m) / i);

	cout << min(ans5, ans2);
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}