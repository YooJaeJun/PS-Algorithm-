#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
#define yes cout << "YES\n";
#define no cout << "NO\n";
const int maxn = 1000;
const double mod = 1e9 + 7;


int n, m;
vi A(maxn, -1), B(maxn, -1);
vvi adj(maxn);
bool visited[maxn];

bool dfs(int a)
{
	visited[a] = true;
	for (auto& b : adj[a])
	{
		if (B[b] == -1 or false == visited[B[b]] and dfs(B[b]))
		{
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}

void solution()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int s;
		cin >> s;
		for (int j = 0; j < s; j++)
		{
			int b;
			cin >> b;
			adj[i].push_back(b - 1);
		}
	}

	int match = 0;
	for (int i = 0; i < n; i++)
	{
		if (A[i] == -1)
		{
			fill(visited, visited + n, false);
			if (dfs(i)) match++;
		}
	}
	cout << match;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}