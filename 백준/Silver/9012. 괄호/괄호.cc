#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;

	while(t--)
	{
		stack<char> st;
		string s;
		cin >> s;

		for (auto& ch : s)
		{
			if (false == st.empty() && 
				st.top() == '(' && 
				ch == ')')
				st.pop();
			else
				st.push(ch);
		}

		if (st.empty())
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}

	return 0;
}