#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
#define yes cout << "YES\n";
#define no cout << "NO\n";
const double mod = 1e9 + 7;

const int maxn = 8000000;
vector<bool> isPrime(maxn, true);
vi primeNumberArr(500001);

void checkPrime()
{
	isPrime[0] = isPrime[1] = false;
	int idx = 0;
	for (int i = 2; i < maxn; i++)
	{
		if (idx >= 500001) return;
		if (isPrime[i])
		{
			primeNumberArr[idx++] = i;
			for (int j = 2; i * j < maxn; j++)
			{
				isPrime[i * j] = false;
			}
		}
	}
}

void solution()
{
	checkPrime();
	int n;
	cin >> n;
	cout << primeNumberArr[n - 1];
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}