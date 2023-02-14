#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define forn(i, n) for (int i = 0; i < (int)n; i++)
const int maxn = 1e9 + 7;
const double mod = 1e9 + 7;

void solution()
{
	int n;
	cin >> n;
	vi a(n), b(n);
	forn(i, n) cin >> a[i];
	forn(i, n) cin >> b[i];

	int dif = maxn;
	forn(i, n)
	{
		if (b[i] != 0) dif = min(dif, a[i] - b[i]);
		if (dif < 0)
		{
			no;
			return;
		}
	}

	forn(i, n)
	{
		if (dif < a[i] - b[i]) 
		{
			no; 
			return;
		}
		else if (b[i] != 0 and dif > a[i] - b[i])
		{
			no; 
			return;
		}
	}
	yes;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}





// 내 다른 풀이
/*

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
	int n;
	cin >> n;
	vi a(n), b(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];

	int least = -1;	// b[i] == 0인 쌍 중 최대의 차이. b[i]가 0이 아니면 최소한 이 차이 이상을 보장해야 함
	for (int i = 0; i < n; i++)
	{
		int cur = a[i] - b[i];

		if (cur < 0)
		{
			no;
			return;
		}
		else if (b[i] == 0)
		{
			least = max(least, cur);
		}
	}

	int dif = -1;
	for (int i = 0; i < n; i++)
	{
		int cur = a[i] - b[i];

		if (b[i] == 0)
			continue;
		if (cur >= least and (dif == -1 or cur == dif))
		{
			dif = cur;
			continue;
		}
		else
		{
			no;
			return;
		}
	}
	yes;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}

*/