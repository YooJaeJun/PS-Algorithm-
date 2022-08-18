#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using db = deque<bool>;
using ddb = deque<deque<bool>>;
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define forn1(i, n) for (int i = 1; i <= (int)n; i++)
#define inGrid() ((nr >= 0) and (nr < n) and (nc >= 0) and (nc < m))
int dr[4] = { 0,0,-1,1 };
int dc[4] = { -1,1,0,0 };	// 좌우상하

struct Score
{
	int score;
	int idx;
	bool operator<(const Score& other) const
	{
		return score < other.score;
	}
};

void solution()
{
	vector<Score> score(8);
	forn(i, 8)
	{
		cin >> score[i].score;
		score[i].idx = i + 1;
	}
	sort(score.begin(), score.end());

	int sum = 0;
	for (int i = 7; i > 2; i--)
		sum += score[i].score;

	cout << sum << '\n';
	vi ans;
	for (int i = 7; i > 2; i--)
		ans.push_back(score[i].idx);
	sort(ans.begin(), ans.end());
	forn(i, 5) cout << ans[i] << ' ';
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solution();
	return 0;
}