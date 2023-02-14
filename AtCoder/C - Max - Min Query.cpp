#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
#define yes cout << "YES\n";
#define no cout << "NO\n";
const int maxn = 100001;
const double mod = 1e9 + 7;


void solution()
{
	int q;
	cin >> q;
	map<int, int> dic;
	while (q--)
	{
		int command;
		cin >> command;
		if (command == 1)
		{
			int x;
			cin >> x;
			dic[x]++;
		}
		else if (command == 2)
		{
			int x, c;
			cin >> x >> c;
			dic[x] -= c;
		}
		else
		{
			int minn = dic.begin()->first, maxn = (--dic.end())->first;
			for (auto it = dic.begin(); it->second <= 0; ) minn = (++it)->first;
			for (auto it = (--dic.end()); it->second <= 0; ) maxn = (--it)->first;
			
			cout << maxn - minn << '\n';
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