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


void solution()
{
	string s;
	cin >> s;
	stack<int> st;
	int cnt = 0, coef = 0;

	for (int i = 0; i < s.size(); i++)
	{
		if (st.empty()) st.push(s[i]);
		else if (st.top() == '(' && s[i] == ')')
		{
			if (s[i - 1] == '(')	// 레이저
			{
				cnt += coef;
			}
			else
			{
				coef--;
			}
			st.pop();
		}
		else
		{
			st.push(s[i]);
			if (s[i - 1] != ')')	// 전에 막대기였을 때만
			{
				cnt++;
				coef++;
			}
		}
	}
	cout << cnt;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}