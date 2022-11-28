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
	string s1, s2;
	cin >> s1 >> s2;
	if (s1.size() < s2.size()) swap(s1, s2);
	int size1 = s1.size(), size2 = s2.size();
	int diff = size1 - size2;
	bool factor = 0;
	string ans;

	for (int i = size1 - 1; i >= 0; i--)
	{
		int digit = factor + s1[i] - '0';
		factor &= 0;

		int s2Idx = i - diff;
		if (s2Idx >= 0)
		{
			digit += s2[s2Idx] - '0';
		}

		if (digit >= 2)
		{
			digit %= 2;
			factor = 1;
		}

		ans.push_back(digit + '0');
	}

	if (factor == 1) ans += '1';

	while (ans.size() != 1 and ans.back() == '0')
	{
		ans.pop_back();
	}
	reverse(ans.begin(), ans.end());

	cout << ans;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solution();
	return 0;
}