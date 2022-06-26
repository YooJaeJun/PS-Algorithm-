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
#define forn1(i, n) for (int i = 1; i <= (int)n; i++)
const int maxn = 1000;
const double mod = 1e9 + 7;


void solution()
{
	vi T;
	for (int i = 1; ; i++)
	{
		int num = i * (i + 1) / 2;
		if (num > maxn) break;
		T.push_back(num);
	}

	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int target;
		cin >> target;
		bool flag = false;
		int siz = (int)T.size();

		for (int i = 0; i < siz and T[i] < target and false == flag; i++)
		{
			for (int j = i; j < siz and T[j] < target and false == flag; j++)
			{
				for (int k = j; k < siz and false == flag; k++)
				{
					int sum = T[i] + T[j] + T[k];
					if (sum < target) continue;
					else if (sum == target)
					{
						flag = true;
						break;
					}
					else if (sum > target) break;
				}
			}
		}
		
		if (flag) cout << 1 << '\n';
		else cout << 0 << '\n';
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