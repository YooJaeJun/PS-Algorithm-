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


void solution()
{
	int t;
	cin >> t;

	enum rcp { R, S, P };
	vvi p1(3, vi(3)), p2(3, vi(3));
	p1[R][S] = p1[S][P] = p1[P][R] = 
		p2[R][S] = p2[S][P] = p2[P][R] = 1;

	while (t--)
	{
		int n;
		cin >> n;
		int p1Score = 0, p2Score = 0;

		forn(i, n)
		{
			char ch1, ch2;
			cin >> ch1 >> ch2;
			int num1 = (ch1 == 'R' ? R : ch1 == 'S' ? S : P);
			int num2 = (ch2 == 'R' ? R : ch2 == 'S' ? S : P);
			p1Score += p1[num1][num2];
			p2Score += p2[num2][num1];
		}
		if (p1Score == p2Score) cout << "TIE\n";
		else
		{
			cout << "Player ";
			if (p1Score > p2Score) cout << "1\n";
			else cout << "2\n";
		}
	}
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solution();
	return 0;
}