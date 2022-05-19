#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
#define yes cout << "YES\n";
#define no cout << "NO\n";
const int maxn = 100'001;
const double mod = 1e9 + 7;

int n;
vi arr, visited;
int ans = 0;

void bt(vi& cur, int depth)
{
	if (depth == n)
	{
		int sum = 0;
		for (int i = 1; i < n; i++)
		{
			sum += abs(cur[i - 1] - cur[i]);
		}
		ans = max(ans, sum);
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (visited[i]) continue;
		visited[i] = true;
		cur.push_back(arr[i]);
		bt(cur, depth + 1);
		cur.pop_back();
		visited[i] = false;
	}
}

void solution()
{
	cin >> n;
	arr = vi(n);
	visited = vi(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	vi cur;
	bt(cur, 0);

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