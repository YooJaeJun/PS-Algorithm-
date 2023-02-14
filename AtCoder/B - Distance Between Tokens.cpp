#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
#define yes cout << "YES\n";
#define no cout << "NO\n";
const int maxn = 100001;
const double mod = 1e9 + 7;


void solution()
{
	int h, w;
	cin >> h >> w;
	char c;
	int x1, y1, x2, y2;
	int idx = 0;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> c;
			if (c == 'o' && idx == 0) x1 = i, y1 = j, idx += 1;
			else if (c == 'o') x2 = i, y2 = j;
		}
	}
	cout << abs(x1 - x2) + abs(y1 - y2);
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}