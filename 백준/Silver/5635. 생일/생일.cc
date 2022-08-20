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


struct info
{
	string name;
	int day, month, year;
	bool operator<(const info& other) const
	{
		if (year == other.year)
			if (month == other.month)
				return day < other.day;
			else return month < other.month;
		else return year < other.year;
	}
};

void solution()
{
	int n;
	cin >> n;
	vector<info> v(n);
	forn(i, n) 
		cin >> v[i].name >> v[i].day >> v[i].month >> v[i].year;
	sort(v.begin(), v.end());
	cout << v.back().name << '\n' << v.front().name;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solution();
	return 0;
}