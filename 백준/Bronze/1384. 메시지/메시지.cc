#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using db = deque<bool>;
using ddb = deque<deque<bool>>;
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define forn1(i, n) for (int i = 1; i <= (int)n; i++)
const int maxn = 1e9 + 7;
const int mod = 1000;

void solution()
{
	int order = 0;
	while (++order)
	{
		int n;
		cin >> n;
		if (n == 0) break;

		vector<string> vs(n);
		vector<string> pn(n);
		forn(i, n)
		{
			cin >> vs[i];
			char ch;

			forn(j, n - 1)
			{
				cin >> ch;
				pn[i] += ch;
			}
		}

		cout << "Group " << order << '\n';
		bool flag = false;
		forn(i, n)
		{
			forn(j, n - 1)
			{
				if (pn[i][j] == 'N')
				{
					int idx = 0;
					if (i - (j + 1) < 0) idx = i - (j + 1) + n;
					else idx = i - (j + 1);
					cout << vs[idx] << " was nasty about " << vs[i] << '\n';
					flag = true;
				}
			}
		}
		if (flag == false)
		{
			cout << "Nobody was nasty" << '\n';
		}
		cout << '\n';
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