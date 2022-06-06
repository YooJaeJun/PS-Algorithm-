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
	int n, m;
	cin >> n >> m;
	vi set(m), one(m);
	for (int i = 0; i < m; i++)
		cin >> set[i] >> one[i];

	sort(set.begin(), set.end());
	sort(one.begin(), one.end());

	int ans = 0;
	// 6개씩
	int setPrice = set[0] * (n / 6);
	int onePrice = one[0] * ((n / 6) * 6);	// 같은 양 비교 위해 int 형변환 시 버림 이용
	if (onePrice > setPrice) ans += setPrice;
	else ans += onePrice;
	// 나머지
	setPrice = set[0];
	onePrice = one[0] * (n % 6);
	if (onePrice > setPrice) ans += setPrice;
	else ans += onePrice;

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