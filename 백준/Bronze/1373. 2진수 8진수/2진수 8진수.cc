#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
#define yes cout << "YES\n";
#define no cout << "NO\n";
const int maxn = 100001;
const double mod = 1e9 + 7;


string binToOct(string s)
{
	string ret;
	for (int i = s.size() - 1; i >= 0; i -= 3)
	{
		int splitedSum = 0;
		splitedSum += (s[i] - '0');
		if (i >= 1) splitedSum += 2 * (s[i - 1] - '0');
		if (i >= 2) splitedSum += 4 * (s[i - 2] - '0');
		ret += to_string(splitedSum);
	}
	return ret;
}

void solution()
{
	string s;
	cin >> s;
	string result = binToOct(s);
	for (int i = result.size() - 1; i >= 0; i--)
	{
		cout << result[i];
	}
	return;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}