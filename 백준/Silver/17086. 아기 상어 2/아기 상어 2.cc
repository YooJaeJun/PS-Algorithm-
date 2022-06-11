#include <bits/stdc++.h>
#include <unordered_map>
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


struct coord
{
	int x, y;
};

int checkSafeDist(coord a, coord b)
{
	int xdif = abs(a.x - b.x);
	int ydif = abs(a.y - b.y);
	return max(xdif, ydif);	// 대각선 고려 최단거리
}

void solution()
{
	int n, m;
	cin >> n >> m;
	vector<coord> shark;
	forn(i, n)
	{
		forn(j, m)
		{
			int num;
			cin >> num;
			if (num == 1) shark.push_back({ i, j });
		}
	}

	int ans = 0;
	forn(i, n)
	{
		forn(j, m)
		{
			int safedist = 1e9;
			forn(k, shark.size())
			{
				safedist = min(safedist, checkSafeDist(shark[k], { i, j }));	// 안전 거리
			}
			ans = max(ans, safedist);
		}
	}
	cout << ans;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}