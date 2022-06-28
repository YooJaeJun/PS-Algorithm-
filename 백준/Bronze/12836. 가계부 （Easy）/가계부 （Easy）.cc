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
	int n, q;
	cin >> n >> q;
	vi arr(n + 1);
	while (q--)
	{
		int command, p, q;
		cin >> command >> p >> q;
		if (command == 1) arr[p] += q;
		else
		{
			int sum = 0;
			for (int i = p; i <= q; i++)
			{
				sum += arr[i];
			}
			cout << sum << '\n';
		}
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