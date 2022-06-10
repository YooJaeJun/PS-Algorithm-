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


void solution()
{
	int a, b;
	cin >> a >> b;
	unordered_map<int, int> A(a), B(b);

	int cnt = 0;
	forn(i, a)
	{
		int num;
		cin >> num;
		A[num] = 1;
	}
	forn(i, b)
	{
		int num;
		cin >> num;
		B[num] = 1;
		if (A[num] != 1) cnt++;
	}

	for (auto& a : A) 
		if (B[a.first] != 1) 
			cnt++;

	cout << cnt;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}