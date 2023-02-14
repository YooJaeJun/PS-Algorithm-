#include <bits/stdc++.h>
#pragma warning(disable: 4996)
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
	int k;
	cin >> k;
	int h = (k >= 60 ? 1 : 0) + 21;
	int m = k % 60;
	string mstr = to_string(m);
	mstr = mstr.size() == 1 ? '0' + mstr : mstr;
	string ans = to_string(h) + ":" + mstr;
	cout << ans;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	//  cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}