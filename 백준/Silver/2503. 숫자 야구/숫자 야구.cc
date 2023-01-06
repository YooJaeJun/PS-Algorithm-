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
	vector<string> candidates;
	db visited(10);
	
	function<void(string, int)> BackTracking = [&](string cur, int depth)
	{
		if (depth == 3)
		{
			candidates.emplace_back(cur);
			return;
		}

		for (int i = 1; i < 10; i++)
		{
			if (visited[i]) continue;
			visited[i] = true;
			cur += i + '0';
			BackTracking(cur, depth + 1);
			cur.pop_back();
			visited[i] = false;
		}
	};
	BackTracking("", 0);

	int n;
	cin >> n;
	vector<string> newCandi;

	forn(i, n)
	{
		newCandi.clear();

		string input;
		cin >> input;
		int inputStrike = 0, inputBall = 0;
		cin >> inputStrike >> inputBall;

		for (auto& can : candidates)
		{
			int curStrike = 0, curBall = 0;

			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (can[i] == input[j])
					{
						if (i == j) curStrike++;
						else curBall++;
						break;
					}
				}
			}
			
			if (curStrike == inputStrike && curBall == inputBall)
			{
				newCandi.emplace_back(can);
			}
		}

		candidates = move(newCandi);
	}

	cout << candidates.size();
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solution();
	return 0;
}