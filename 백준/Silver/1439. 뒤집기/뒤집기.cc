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
const int maxn = 1e9 + 7;
const double mod = 1e9 + 7;


void solution()
{
	string s;
	cin >> s;
	int zero = 0, one = 0;
	int state[2]{ 0, 0 };
	state[s[0] - '0']++;
	
	forn(i, s.size() - 1)
		if (s[i] != s[i + 1])
			state[s[i + 1] - '0']++;

	cout << min(state[0], state[1]);
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}