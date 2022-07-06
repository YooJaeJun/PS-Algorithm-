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
const int maxn = 1000;
const double mod = 1e9 + 7;


void solution()
{
	int n;
	cin >> n;
	vi arr(n);
	forn(i, n) arr[i] = i + 1;
	vi visited(n);

	function<void(vector<int>&)> comb = [&](vector<int>& cur)
	{
		if (cur.size() == n)
		{
			for (auto& elem : cur) cout << elem << ' ';
			cout << '\n';
			return;
		}
		for (int i = 0; i < n; i++)
		{
			if (visited[i]) continue;
			visited[i] = true;
			cur.push_back(arr[i]);
			comb(cur);
			cur.pop_back();
			visited[i] = false;
		}
	};
	vector<int> cur;
	comb(cur);
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}