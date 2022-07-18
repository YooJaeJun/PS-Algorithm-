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
#define gridCheck() if (nx < 0 or nx >= n or ny < 0 or ny >= n) continue;


void solution()
{
	int n, newScore, p;
	cin >> n >> newScore >> p;
	vi score(n);
	forn(i, n) cin >> score[i];

	int idx = n, rank = 1, coef = 0;		// 동점 시 다음 랭킹 보정
	forn(i, n)
	{
		if (score[i] < newScore)
		{
			idx = i;
			break;
		}
		else if (score[i] == newScore)
		{
		}
		else if (i > 0 and score[i] == score[i - 1])
		{
			coef++;
		}
		else
		{
			rank += coef + 1;
			coef = 0;
		}
	}
	if (idx + 1 > p) cout << -1;
	else cout << rank + coef;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solution();
	return 0;
}