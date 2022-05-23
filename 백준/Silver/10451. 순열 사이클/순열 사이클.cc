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

void dfs(vi& nodes, vi& visited, int start)
{
	if (visited[start]) return;
	visited[start] = true;
	dfs(nodes, visited, nodes[start]);
}

void solution()
{
	int n;
	cin >> n;
	vi nodes(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> nodes[i];
	}

	vi visited(n + 1);
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (visited[i]) continue;
		dfs(nodes, visited, i);
		cnt++;
	}
	cout << cnt << '\n';
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}