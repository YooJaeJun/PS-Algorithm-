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
	int n;
	cin >> n;
	string s1 = to_string(n);
	string s2;
	forn1(i, n)
	{
		s2 += to_string(i);
	}

	for (int i = 0; i < s2.size(); i++)
	{
		if (s2[i] == s1[0])
		{
			bool flag = true;
			for (int j = 1; j < s1.size(); j++) 
			{
				if (s2[i + j] != s1[j])
				{
					flag = false;
					break;
				}
			}

			if (flag)
			{
				cout << i + 1;
				return;
			}
		}
	}
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solution();
	return 0;
}