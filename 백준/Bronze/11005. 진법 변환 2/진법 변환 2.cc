#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
#define yes cout << "YES\n";
#define no cout << "NO\n";
const int maxn = 100001;
const double mod = 1e9 + 7;

string ans;

void toNotate(int n, int b)
{
	int mod = n % b;
	string s;
	if (mod >= 10) s = 'A' + mod - 10;
	else s = to_string(mod);
	ans = s + ans;
	if (n < b) return;
	toNotate(n / b, b);
}

void solution()
{
	int n, b;
	cin >> n >> b;
	toNotate(n, b);
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