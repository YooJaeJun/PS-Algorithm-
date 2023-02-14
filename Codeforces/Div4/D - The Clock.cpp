#include <bits/stdc++.h>
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


bool isPal(string s)
{
	return s[0] == s[3] and s[1] == s[2];
}

void solution()
{
	string s;
	cin >> s;
	string hStr = s.substr(0, 2);
	string mStr = s.substr(3, 2);
	int h = stoi(hStr);
	int m = stoi(mStr);
	
	int x;
	cin >> x;

	int cnt = 0;
	unordered_map<string, int> dic;
	while (1)
	{
		m += x;
		h += m / 60;
		m %= 60;
		if (h >= 24) h %= 24;
		
		hStr = to_string(h);
		if (hStr.size() == 1) hStr = '0' + hStr;
		
		mStr = to_string(m);
		if (mStr.size() == 1) mStr = '0' + mStr;

		string str = hStr + mStr;

		if (dic[str]) break;
		else
		{
			dic[str] = 1;
			if (isPal(str)) cnt++;
		}
	}
	cout << cnt << '\n';
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}