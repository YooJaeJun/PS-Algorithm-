#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using db = deque<bool>;
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define forn(i, n) for (int i = 0; i < (int)n; i++)
const int maxn = 1e9 + 7;
const double mod = 1e9 + 7;


vector<deque<char>> gear;
const int leftIdx = 6, rightIdx = 2;	// 맞닿은 인덱스
int t;

void rotate(int dir, int idx)
{
	if (dir == -1)
	{
		gear[idx].push_back(gear[idx].front());
		gear[idx].pop_front();
	}
	else
	{
		gear[idx].push_front(gear[idx].back());
		gear[idx].pop_back();
	}
}

void roatateLeft(int dir, int idx, int i)
{
	if (idx - i < 0) return;

	if (idx - i >= 0)
	{
		if (gear[idx - i + 1][leftIdx] != gear[idx - i][rightIdx])
		{
			roatateLeft(-dir, idx, i + 1);
			rotate(-dir, idx - i);
		}
	}
}

void roatateRight(int dir, int idx, int i)
{
	if (idx + i >= t) return;

	if (idx + i < t)
	{
		if (gear[idx + i - 1][rightIdx] != gear[idx + i][leftIdx])
		{
			roatateRight(-dir, idx, i + 1);
			rotate(-dir, idx + i);
		}
	}
}

void solution()
{
	cin >> t;
	gear.resize(t);

	forn(i, t)
	{
		string s;
		cin >> s;
		forn(j, s.size())
		{
			gear[i].push_back(s[j]);
		}
	}

	int k;
	cin >> k;
	forn(i, k)
	{
		int idx, dir;
		cin >> idx >> dir;
		--idx;
		roatateLeft(dir, idx, 1);
		roatateRight(dir, idx, 1);
		rotate(dir, idx);
	}

	int ans = 0;
	forn(i, t)
	{
		if (gear[i][0] == '1') ++ans;
	}
	cout << ans;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}