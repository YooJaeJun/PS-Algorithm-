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


db prime(1e7 + 1, true);
vi primeVec;

void solution()
{
	auto CheckPrime = [&]()
	{
		prime[0] = prime[1] = false;
		for (int i = 2; i <= 1e7; i++)
		{
			if (false == prime[i]) continue;
			primeVec.push_back(i);

			for (int j = 2; i * j <= 1e7; j++)
			{
				prime[i * j] = false;
			}
		}
	};
	CheckPrime();

	int a, b;
	cin >> a >> b;
	int ans = 0;

	auto CheckAlmostPrime = [&](const int a, const int b)
	{
		for (auto& p : primeVec)
		{
			int powResult = p;
			while (powResult <= b / p)
			{
				powResult *= p;
				if (a <= powResult) ans++;
			}
		}
	};
	CheckAlmostPrime(a, b);

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