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
	vector<string> vs(n);
	forn(i, n) cin >> vs[i];

	sort(vs.begin(), vs.end(), [&](string s1, string s2)
		{
			if (s1.size() == s2.size())
			{
				int s1sum = 0, s2sum = 0;
				for (auto& elem : s1)
				{
					if (elem >= '0' && elem <= '9') s1sum += elem - '0';
				}
				for (auto& elem : s2)
				{
					if (elem >= '0' && elem <= '9') s2sum += elem - '0';
				}
				if (s1sum == s2sum)
				{
					return s1 < s2;
				}
				return s1sum < s2sum;
			}
			return s1.size() < s2.size();
		});

	for (auto& elem : vs)
	{
		cout << elem << '\n';
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