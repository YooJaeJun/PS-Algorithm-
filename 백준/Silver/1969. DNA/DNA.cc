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
	int n, m;
	cin >> n >> m;
	vector<string> dna(n);
	forn(i, n) cin >> dna[i];

	int ans = 0;
	string ansStr;
	map<char, int> dic;
	forn(i, m)
	{
		forn(j, n)
		{
			dic[dna[j][i]]++;
		}

		int max = 0;
		char maxCh;
		for (auto& elem : dic)
		{
			if (max < elem.second)
			{
				max = elem.second;
				maxCh = elem.first;
			}
		}
		ans += n - max;
		ansStr += maxCh;
		dic.clear();
	}
	cout << ansStr << '\n' << ans;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solution();
	return 0;
}