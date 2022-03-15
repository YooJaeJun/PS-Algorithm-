#include <iostream>
#include <stack>
using namespace std;

int main() {
	string s;
	int n;
	cin >> n;
	for (int i = 0; i != n; i++) {
		cin >> s;
		stack<int> st;
		for (int j = 0; j != s.size(); j++) {
			if (st.empty()) {
				st.push(s[j]);
			}
			else if (st.top() == '(' && s[j] == ')') {
				st.pop();
			}
			else {
				st.push(s[j]);
			}
		}
		if (st.empty()) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	

	return 0;
}