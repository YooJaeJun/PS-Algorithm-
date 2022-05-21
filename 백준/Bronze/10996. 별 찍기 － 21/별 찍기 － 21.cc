#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
#define yes cout << "YES\n";
#define no cout << "NO\n";
const int maxn = 100'001;
const double mod = 1e9 + 7;


void solution()
{
	int n;
	cin >> n;
	if (n == 1)
	{
		cout << '*';
		return;
	}
	for (int i = 0; i < n * 2; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i % 2)
			{
				if (j % 2) cout << '*';
				else cout << ' ';
			}
			else
			{
				if (j % 2) cout << ' ';
				else cout << '*';
			}
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