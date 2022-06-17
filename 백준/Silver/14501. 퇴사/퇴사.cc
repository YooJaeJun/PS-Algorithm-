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
const int maxn = 1e9 + 7;
const double mod = 1e9 + 7;


int n;
struct consulting
{
	int duration, price;
};
vector<consulting> arr(n);
int ans = 0;

void backTraking(int idx, int price)
{
	ans = max(ans, price);
	if (idx == n) return;

	for (int i = idx; i <= n; i++)
	{
		if (i + arr[i].duration > n) continue;
		backTraking(i + arr[i].duration, price + arr[i].price);
	}
}

void solution()
{
	cin >> n;
	arr.resize(n + 1);
	forn(i, n)
		cin >> arr[i].duration >> arr[i].price;
	backTraking(0, 0);
	cout << ans;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}