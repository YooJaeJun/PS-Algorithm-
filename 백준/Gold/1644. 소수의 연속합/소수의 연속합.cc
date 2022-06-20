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

bool prime[4'000'001];
vi primes;

void checkPrime(int n)
{
	prime[0] = prime[1] = false;
	for (int i = 2; i <= n; i++)
	{
		if (false == prime[i]) continue;
		primes.push_back(i);
		if (primes.size() > 1) primes.back() += primes[primes.size() - 2];	// 누적합

		for (int j = 2; i * j <= n; j++)
		{
			prime[i * j] = false;
		}
	}
}

void solution()
{
	int n;
	cin >> n;
	fill(prime, prime + 4'000'001, true);
	checkPrime(n);

	int i = -1, j = 0, res = 0;
	int ans = 0;
	if (primes.empty() or primes.size() == 1)
	{
		if (prime[n]) ans++;
		cout << ans;
		return;
	}

	while (j < primes.size())
	{
		res = primes[j];
		if (i > -1) res -= primes[i];

		if (res < n) j++;
		else if (res > n) i++;
		else
		{
			ans++;
			j++; i++;
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