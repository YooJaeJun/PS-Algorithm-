#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
	int t;
	cin >> t;
	queue<int> q;
	for (int i = 1; i <= t; i++) {
		q.push(i);
	}
	stack<int> st;
	string s;
	while (t--) {
		int elem;
		cin >> elem;
		
		if (st.empty() || st.top() < elem) {
			for (int i = q.front(); i <= elem; i++) {
				st.push(i);
				s += '+';
				q.pop();
			}
			st.pop();
			s += '-';
		}
		else if(false == st.empty() && st.top() == elem) {
			st.pop();
			s += '-';
		}
		else {
			printf("NO");
			return 0;
		}
	}
	for (auto& elem : s) {
		printf("%c\n", elem);
	}

	return 0;
}