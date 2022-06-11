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


vector<deque<char>> gear(4);
const int leftIdx = 6, rightIdx = 2;	// 맞닿은 인덱스

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

void checkSideRotation(int idx, int dir)
{
	if (idx - 1 >= 0)
	{
		if (gear[idx][leftIdx] != gear[idx - 1][rightIdx])
		{
			if (idx - 2 >= 0)
			{
				if (gear[idx - 1][leftIdx] != gear[idx - 2][rightIdx])
				{
					if (idx - 3 >= 0)
					{
						if (gear[idx - 2][leftIdx] != gear[idx - 3][rightIdx])
						{
							rotate(-dir, idx - 3);
						}
					}
					rotate(dir, idx - 2);
				}
			}
			rotate(-dir, idx - 1);
		}
	}
	if (idx + 1 < 4)
	{
		if (gear[idx][rightIdx] != gear[idx + 1][leftIdx])
		{
			if (idx + 2 < 4)
			{
				if (gear[idx + 1][rightIdx] != gear[idx + 2][leftIdx])
				{
					if (idx + 3 < 4)
					{
						if (gear[idx + 2][rightIdx] != gear[idx + 3][leftIdx])
						{
							rotate(-dir, idx + 3);
						}
					}
					rotate(dir, idx + 2);
				}
			}
			rotate(-dir, idx + 1);
		}
	}
}

void solution()
{
	forn(i, 4)
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
		checkSideRotation(idx, dir);
		rotate(dir, idx);
	}

	int ans = 0;
	forn(i, 4)
	{
		if (gear[i][0] == '1') ans += pow(2, i);
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