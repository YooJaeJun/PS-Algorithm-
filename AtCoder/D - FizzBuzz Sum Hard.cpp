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


int gcd(int a, int b)
{
	if (a == 0) return b;
	return gcd(b % a, a);
}
int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

void solution()
{
	int n, a, b;
	cin >> n >> a >> b;
	int sum = n * (1 + n) / 2;
	int subA = (n / a) * (a + ((n / a) * a)) / 2;
	int subB = (n / b) * (b + ((n / b) * b)) / 2;
	int c = lcm(a, b);
	int plus = (n / c) * (c + ((n / c) * c)) / 2;
	cout << sum - subA - subB + plus << '\n';
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}