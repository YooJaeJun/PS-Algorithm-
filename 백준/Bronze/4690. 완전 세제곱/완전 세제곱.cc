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
	int a, b, c, d; 
	bool operator>(const info& other) const
	{
		if (a == other.a)
		{
			if (b == other.b)
			{
				if (c == other.c)
				{
					return d > other.d;
				}
				return c > other.c;
			}
			return b > other.b;
		}
		return a > other.a;
	}
};


void solution()
{
	int sum = 0, a = 0, b = 0, c = 0, d = 0;
	priority_queue<info, vector<info>, greater<info>> pq;

	for (b = 2; b <= 100; b++)
	{
		for (c = b + 1; c <= 100; c++)
		{
			for (d = c + 1; d <= 100; d++)
			{
				sum = b * b * b + c * c * c + d * d * d;

				for (a = 4; a <= 100; a++)
				{
					int a3 = a * a * a;
					if (a3 == sum)
					{
						pq.push({ a, b, c, d });
					}
					else if (a3 > sum) break;
				}
			}
		}
	}

	while (pq.empty() == false)
	{
		a = pq.top().a;
		b = pq.top().b;
		c = pq.top().c;
		d = pq.top().d;
		cout << "Cube = " << a << ", " << "Triple = (" << b << "," << c << "," << d << ")" << '\n';
		pq.pop();
	}

}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solution();
	return 0;
}