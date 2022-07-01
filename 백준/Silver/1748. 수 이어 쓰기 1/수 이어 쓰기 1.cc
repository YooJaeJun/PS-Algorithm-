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
	int n;
	cin >> n;
	int nCopy = n;

	int digit = 0;
	while (n) 
	{ 
		n /= 10;
		digit++;
	}

	int coef = 9;
	int sum = 0;
	for (int i = 1; i < digit; i++)
	{
		sum += (coef * i) - (coef / 10) * i;
		coef = coef * 10 + 9;
	}
	sum += (nCopy - coef / 10) * digit;
	cout << sum;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}