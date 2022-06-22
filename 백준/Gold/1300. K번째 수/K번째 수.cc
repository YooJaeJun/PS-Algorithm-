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
#define forn1(i, n) for (int i = 1; i <= (int)n; i++)
const int maxn = 1e9 + 7;
const double mod = 1e9 + 7;


void solution()
{
	int n, k;
	cin >> n >> k;
	int idxForLessNums = 0;
	int start = 1, end = k, mid;
	while (start <= end)
	{
		mid = (start + end) / 2;

		int cnt = 0;
		for (int row = 1; row <= n; row++)
		{
			cnt += min(mid / row, n);
		}

		if (cnt < k)
			start = mid + 1;
		else
			end = mid - 1;
	}
	cout << start;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}