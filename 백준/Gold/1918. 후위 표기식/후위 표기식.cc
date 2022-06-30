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


void solution()
{
	string s;
	cin >> s;
	stack<char> st;
	for (auto& ch : s)
	{
		if (ch >= 'A' and ch <= 'Z') cout << ch;
		else if (ch == '(') st.push(ch);
		else if (ch == '*' or ch == '/')
		{
			while (st.empty() == false and (st.top() == '*' or st.top() == '/'))
			{
				cout << st.top();
				st.pop();
			}
			st.push(ch);
		}
		else if (ch == '+' or ch == '-')
		{
			while (st.empty() == false and st.top() != '(')
			{
				cout << st.top();
				st.pop();
			}
			st.push(ch);
		}
		else //')'
		{
			while (st.empty() == false and st.top() != '(')
			{
				cout << st.top();
				st.pop();
			}
			if (st.empty() == false) st.pop();	// '(' 빼기
		}
	}
	while (st.empty() == false)
	{
		cout << st.top();
		st.pop();
	}
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}