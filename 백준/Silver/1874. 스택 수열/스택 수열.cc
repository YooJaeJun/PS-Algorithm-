#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	vector<int> inputs(n);

	for (int i = 0; i < n; i++)
		cin >> inputs[i];

	stack<int> st;
	int index = 0, cur = 1;
	string answer;

	while (index < n)
	{
		if (st.empty() || st.top() < inputs[index])
		{
			st.push(cur);
			cur++;
			answer += '+';
		}
		else if (!st.empty() && st.top() == inputs[index])
		{
			st.pop();
			index++;
			answer += '-';
		}
		else
		{
			cout << "NO";
			return 0;
		}
	}

	for (auto& ch : answer)
		cout << ch << '\n';

	return 0;
}
