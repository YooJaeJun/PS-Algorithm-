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


void solution()
{
	unordered_map<string, int> dic;
	dic["R"] = 0;	dic["L"] = 1;	dic["B"] = 2;
	dic["T"] = 3;	dic["RT"] = 4;	dic["LT"] = 5;
	dic["RB"] = 6;	dic["LB"] = 7;
	int dr[8]{ 0, 0, -1, 1, 1, 1, -1, -1 };	// 좌표계 반대
	int dc[8]{ 1, -1, 0, 0, 1, -1, 1, -1 };

	string king, stone;
	cin >> king >> stone;
	int kingR = king[1] - '1';
	int kingC = king[0] - 'A';
	int stoneR = stone[1] - '1';
	int stoneC = stone[0] - 'A';

	int n;
	cin >> n;
	vector<string> commands(n);
	forn(i, n) cin >> commands[i];

	auto checkGrid = [](int a, int b) ->bool
	{
		return (a >= 0) and (a < 8) and (b >= 0) and (b < 8);
	};

	forn(i, n)
	{
		int& moveR = dr[dic[commands[i]]];
		int& moveC = dc[dic[commands[i]]];
		int kingNR = kingR + moveR;
		int kingNC = kingC + moveC;
		if (!checkGrid(kingNR, kingNC)) continue;

		if (kingNR == stoneR and kingNC == stoneC)
		{
			int stoneNR = stoneR + moveR;
			int stoneNC = stoneC + moveC;
			if (!checkGrid(stoneNR, stoneNC)) continue;
			stoneR = stoneNR;
			stoneC = stoneNC;
		}
		kingR = kingNR;
		kingC = kingNC;
	}

	cout << char('A' + kingC) << to_string(kingR + 1) << '\n';
	cout << char('A' + stoneC) << to_string(stoneR + 1) << '\n';
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solution();
	return 0;
}