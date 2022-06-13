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
const int maxn = 100;
const double mod = 1e9 + 7;


void solution()
{
	vi pado(maxn + 1);
	pado[1] = pado[2] = pado[3] = 1;
	pado[4] = pado[5] = 2;
	for (int i = 6; i <= maxn; i++)
	{
		pado[i] = pado[i - 1] + pado[i - 5];
	}

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		cout << pado[n] << '\n';
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