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
	vvi v(n);
	for (int i = 0; i < n; i++)
	{
		v[i].resize(i + 1);

		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || j == i)
				v[i][j] = 1;
			else
				v[i][j] = v[i - 1][j - 1] + v[i - 1][j];

			cout << v[i][j] << ' ';
		}
		cout << '\n';
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