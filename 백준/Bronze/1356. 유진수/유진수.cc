#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using db = deque<bool>;
using ddb = deque<deque<bool>>;
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define forn1(i, n) for (int i = 1; i <= (int)n; i++)
#define inGrid() ((nr >= 0) and (nr < n) and (nc >= 0) and (nc < m))
int dr[4] = { 0,0,-1,1 };
int dc[4] = { -1,1,0,0 };	// 좌우상하


void solution()
{
	string s;
	cin >> s;
	for (int i = 1; i < s.size(); i++)
	{
		int mul1 = 1, mul2 = 1;
		for (int j = 0; j < i; j++)
		{
			mul1 *= s[j] - '0';
		}
		for (int j = i; j < s.size(); j++)
		{
			mul2 *= s[j] - '0';
		}

		if (mul1 == mul2)
		{
			cout << "YES";
			return;
		}
	}
	cout << "NO";
}

int32_t main()
{
	// ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solution();
	return 0;
}