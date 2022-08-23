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

int t, idx;
vi human = { 1, 2, 3, 3, 4, 10 };
vi enemy = { 1, 2, 2, 2, 3, 5, 10 };

void solution()
{
	int score;
	int humanScore = 0;
	forn(i, 6)
	{
		cin >> score;
		humanScore += score * human[i];
	}
	int enemyScore = 0;
	forn(i, 7)
	{
		cin >> score;
		enemyScore += score * enemy[i];
	}
	cout << "Battle " << idx << ": ";
	if (humanScore > enemyScore) cout << "Good triumphs over Evil";
	else if (humanScore < enemyScore) cout << "Evil eradicates all trace of Good";
	else cout << "No victor on this battle field";
	cout << '\n';
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
	for(idx = 1; idx <= t; idx++) solution();
	return 0;
}