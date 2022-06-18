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
const int maxn = 1e9;
const double mod = 1e9 + 7;


struct comp
{
	bool operator()(int a, int b) const
	{
		if (abs(a) == abs(b))
		{
			return a > b;
		}
		return abs(a) > abs(b);
	}
};

void solution()
{
	priority_queue<int, vi, comp> pq;
	int n;
	cin >> n;
	forn(i, n)
	{
		int x;
		cin >> x;
		if (x) pq.push(x);
		else
		{
			if (pq.empty() == false)
			{
				cout << pq.top() << '\n';
				pq.pop();
			}
			else cout << 0 << '\n';
		}
	}
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}