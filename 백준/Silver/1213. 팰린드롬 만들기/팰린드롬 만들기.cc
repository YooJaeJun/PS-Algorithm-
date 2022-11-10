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
	string s;
	cin >> s;
	map<char, int> dic;	// 알파벳, 개수
	for (auto& ch : s) dic[ch]++;
	deque<char> ans;

	if (s.size() == 1)
	{
		cout << s;
		return;
	}
	
	if (s.size() & 1)
	{
		for (auto it = dic.rbegin(); it != dic.rend(); it++)
		{
			if (it->second & 1)
			{
				ans.push_back(it->first);
				it->second--;
				break;
			}
		}
	}

	while (true)
	{
		bool isPush = false;

		for (auto it = dic.rbegin(); it != dic.rend(); it++)
		{
			if (it->second != 0 and !(it->second & 1))
			{
				ans.push_front(it->first);
				ans.push_back(it->first);
				it->second -= 2;
				isPush = true;
				break;
			}
		}

		if (!isPush)
		{
			cout << "I'm Sorry Hansoo";
			return;
		}

		bool isRemainDic = false;

		for (auto& elem : dic)
		{
			if (elem.second != 0)
			{
				isRemainDic = true;
				break;
			}
		}

		if (!isRemainDic) break;
	}

	for (auto& elem : ans)
	{
		cout << elem;
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