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

int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

void solution()
{
	int a, b;
	cin >> a >> b;
	int n = gcd(a, b);
	forn(i, n) cout << 1;	// a, b 최대공약수 구하고 결과 수만큼 1에 1자리만큼 추가하는 규칙 찾기
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}