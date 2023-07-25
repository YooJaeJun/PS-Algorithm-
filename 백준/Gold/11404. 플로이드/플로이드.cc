#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1, vector<int>(n + 1, 1e9));

	for (int i=0; i<m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a][b] = min(adj[a][b], c);
	}

	for (int i = 1; i <= n; i++)
		adj[i][i] = 0;

	for (int k=1; k<=n; k++)
		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++)
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << ((adj[i][j] == 1e9) ? 0 : adj[i][j]) << ' ';

		cout << '\n';
	}

	return 0;
}