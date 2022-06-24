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

struct User
{
	int u;
};

void solution()
{
	int n;
	cin >> n;
	vi arr(n), arrSorted(n);
	forn(i, n)
	{
		cin >> arr[i];
		arrSorted[i] = arr[i];
	}
	sort(arrSorted.begin(), arrSorted.end());
	bool checked[51] = { false };

	forn(i, n)
	{
		int idx = lower_bound(arrSorted.begin(), arrSorted.end(), arr[i]) - arrSorted.begin();
		while (checked[idx]) idx++;

		cout << idx << ' ';
		checked[idx] = true;
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