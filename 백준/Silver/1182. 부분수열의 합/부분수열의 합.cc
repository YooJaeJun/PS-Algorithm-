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

int n, s;
vi arr;
int ans = 0;

void bt(int sum, int depth, int idx)
{
	if (depth == n + 1)
		return;
	if (depth != 0 && sum == s)
		ans++;
	for (int i = idx; i < n; i++)
		bt(sum + arr[i], depth + 1, i + 1);
}

void solution()
{
	cin >> n >> s;
	arr = vi(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	bt(0, 0, 0);

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