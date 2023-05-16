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

vi f;
int cnt = 1, cntDp = 1;

int fib(int n)
{
	if (n <= 2) return 1;
	cnt++;
	return fib(n - 1) + fib(n - 2);
}

int fibDp(int n)
{
	f[1] = f[2] = 1;
	for (int i = 3; i < n; i++)
	{
		cntDp++;
		f[i] = f[i - 1] + f[i - 2];
	}
	return f[n];
}

void solution()
{
	int n;
	cin >> n;
	f.resize(n + 1);
	fib(n);
	fibDp(n);
	cout << cnt << ' ' << cntDp;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}