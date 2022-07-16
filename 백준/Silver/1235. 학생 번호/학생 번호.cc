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
	int n;
	cin >> n;
	vector<string> vs(n);
	forn(i, n) cin >> vs[i];

	unordered_map<string, int> dic;
	int size = vs[0].size();
	int ans = 0;

	for (int i = size - 1; i >= 0; i--)	// 문자열 하나의 현재 자릿수
	{
		dic.clear();
		bool flag = true;
		forn(j, n)	// 문자열들
		{
			string s = vs[j].substr(i, size - i);
			if (dic[s])
			{
				flag = false;
				break;
			}
			else dic[s]++;
		}
		if (flag)
		{
			ans = size - i;
			break;
		}
	}
	cout << ans;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solution();
	return 0;
}