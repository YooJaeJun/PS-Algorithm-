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
	int a, b;
	cin >> a >> b;
	
	db isPrime(b + 1, true);
	isPrime[0] = isPrime[1] = false;
	vi primes;
	vi primeNums(b + 1);
	for (int i = 2; i <= b; i++)
	{
		if (isPrime[i])
		{
			primes.push_back(i);
			for (int j = 2; i * j <= b; j++)
			{
				isPrime[i * j] = false;
				int temp = i * j;
				while (temp % i == 0)
				{
					temp /= i;
					primeNums[i * j]++;		// 소수 세면서 소인수분해한 수까지 세보자
				}
			}
		}
	}
	int ans = 0;
	for (int i = a; i <= b; i++)
	{
		if (isPrime[primeNums[i]]) 
			ans++;
	}
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