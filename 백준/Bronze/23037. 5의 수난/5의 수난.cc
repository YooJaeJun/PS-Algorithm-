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
	int sum = 0;

	while (n > 0)
	{
		int x = n % 10;
		int xSq = x;
		for (int i = 0; i < 4; i++)
			xSq *= x;

		sum += xSq;

		n /= 10;
	}

	cout << sum;
}

int32_t main()
{
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}