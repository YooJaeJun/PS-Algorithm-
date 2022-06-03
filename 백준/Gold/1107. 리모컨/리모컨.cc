#include <bits/stdc++.h>
using namespace std;
// #define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
#define yes cout << "YES\n";
#define no cout << "NO\n";
const int maxn = 100001;
const double mod = 1e9 + 7;

vector<bool> btn(10, true);
string n;
int ans = 1e10;

void bt(string& cur, const int depth)
{
	if (cur.empty() == false) 
		ans = min(ans, abs(stoi(n) - stoi(cur)) + (int)cur.size());
	if (depth == 6) 
		return;

	for (int i = 0; i < 10; i++)
	{
		char ch = '0' + i;
		if (btn[ch - '0'])
		{
			cur += ch;
			bt(cur, depth + 1);
			cur.pop_back();
		}
	}
}

void solution()
{
	cin >> n;
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int num;
		cin >> num;
		btn[num] = false;
	}

	if (n == "100")
	{
		cout << 0; return;
	}

	string cur;
	bt(cur, 0);

	cout << min(ans, abs(100 - stoi(n)));
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}