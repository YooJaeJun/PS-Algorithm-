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
	int diff = s1.size() - s2.size();
	int carry = 0;

	for (int i = s1.size() - 1; i >= 0; i--)
	{
		int sum = s1[i] - '0' + carry;
		if (i - diff >= 0) sum += (s2[i - diff] - '0');

		if (sum > 1)
		{
			s1[i] = sum == 2 ? '0' : '1';
			carry = 1;
		}
		else
		{
			s1[i] = '0' + sum;
			carry = 0;
		}
	}
	if (carry > 0) s1 = '1' + s1;
	while (s1[0] == '0' and s1.size() != 1) s1.erase(s1.begin());

	cout << s1 << '\n';
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solution();
	return 0;
}