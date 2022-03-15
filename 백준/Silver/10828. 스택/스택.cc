#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	stack<int> st;
	for (int i = 0; i != n; i++) {
		string s;
		cin >> s;
		if (s == "push") {
			int x;
			cin >> x;
			st.push(x);
		}
		else if (s == "pop") {
			if (st.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << st.top() << '\n';
				st.pop();
			}
		}
		else if (s == "size") {
			cout << st.size() << '\n';
		}
		else if (s == "empty") {
			cout << st.empty() << '\n';
		}
		else if (s == "top") {
			if (st.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << st.top() << '\n';
			}
		}
	}

	return 0;
}