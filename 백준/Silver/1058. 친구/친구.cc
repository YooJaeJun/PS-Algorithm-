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
const double mod = 1e9 + 7;
#define checkInGrid() if (nx < 0 or nx >= n or ny < 0 or ny >= m) continue;


void solution()
{
	int n;
	cin >> n;
	vvi nodes(n);
	string s;
	forn(i, n)
	{
		cin >> s;
		forn(j, n) if (s[j] == 'Y') nodes[i].push_back(j);
	}

	vi ans(n);
	db visited(n);

	auto bfs = [&](int start)
	{
		queue<pii> q;
		q.push({ start, 0 });
		fill(visited.begin(), visited.end(), false);
		visited[start] = true;

		while (q.empty() == false)
		{
			int cur = q.front().first;
			int depth = q.front().second;
			q.pop();

			for (auto& next : nodes[cur])
			{
				if (depth == 2) continue;
				if (visited[next]) continue;
				visited[next] = true;
				q.push({ next, depth + 1 });
				ans[start]++;
			}
		}
	};
	forn(i, n) bfs(i);

	cout << *max_element(ans.begin(), ans.end());
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solution();
	return 0;
}