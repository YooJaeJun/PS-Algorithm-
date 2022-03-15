#include <iostream>
#include <vector>
#include <stack>
#include <cstdio>
using namespace std;

int main() {
	while (1) {
		char str[101] = {0, };

		scanf("%[^\n]s", str);
		getchar();
		if (str[0] == '.') {
			break;
		}

		stack<char> st;
		for (auto& ch : str) {
			if (ch == ')' && st.empty() == false && st.top() == '(') {
				st.pop();
			}
			else if (ch == ']' && st.empty() == false && st.top() == '[') {
				st.pop();
			}
			else if(ch == '(' || ch == '[' || ch == ']' || ch == ')') {
				st.push(ch);
			}
		}
		
		if (st.empty()) {
			printf("yes\n");
		}
		else {
			printf("no\n");
		}
	}

	return 0;
}