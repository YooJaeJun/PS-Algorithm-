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


void solution()
{
	int n;
	cin >> n;
	vvi grid(n, vi(5));
	forn(i, n) forn(j, 5) cin >> grid[i][j];

	vi relation(n);
	forn(student, n)
	{
		unordered_set<int> dic;
		forn(col, 5)
		{
			forn(row, n)
			{
				if (student == row) continue;
				if (grid[student][col] == grid[row][col]) dic.insert(row);
			}
		}
		relation[student] = dic.size();
	}
	cout << max_element(relation.begin(), relation.end()) - relation.begin() + 1;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}