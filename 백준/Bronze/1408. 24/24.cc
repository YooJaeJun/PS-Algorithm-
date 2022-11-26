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
	string start, end;
	cin >> start >> end;

	int h = stoi(start.substr(0, 2));
	int m = stoi(start.substr(3, 2));
	int s = stoi(start.substr(6, 2));
	int startT = h * 3600 + m * 60 + s;

	h = stoi(end.substr(0, 2));
	m = stoi(end.substr(3, 2));
	s = stoi(end.substr(6, 2));
	int endT = h * 3600 + m * 60 + s;
	
	int t = endT - startT;
	if (t < 0) t += 24 * 3600;

	h = t / 3600;
	m = (t % 3600) / 60;
	s = t % 60;

	if (h < 10) cout << 0;
	cout << h << ':';
	if (m < 10) cout << 0;
	cout << m << ':';
	if (s < 10) cout << 0;
	cout << s;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solution();
	return 0;
}