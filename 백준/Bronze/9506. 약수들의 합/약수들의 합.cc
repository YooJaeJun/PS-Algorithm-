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
	int n;
	while (1)
	{
		cin >> n;
		if (n == -1) break;
		float root = sqrt(n);
		set<int> remains{ 1 };

		for (int i = 2; i < root; i++)
		{
			if (n % i == 0)
			{
				remains.insert(i);
				remains.insert(n / i);
			}
		}
		if ((int)root * root == n)
		{
			remains.insert(root);
		}

		int sum = 0;
		for (auto& elem : remains)
		{
			sum += elem;
		}

		if (sum != n)
		{
			cout << n << " is NOT perfect.\n";
		}
		else
		{
			cout << n << " = ";
			
			int idx = 0;
			for (auto& elem : remains)
			{
				if (idx < remains.size() - 1)
				{
					cout << elem << " + ";
				}
				else cout << elem << '\n';
				idx++;
			}
		}
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