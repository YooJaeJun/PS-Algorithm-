#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack<char> st1;
	string s;
	cin >> s;
	for (auto& elem : s) {
		st1.push(elem);
	}
	stack<char> st2;
	int command_cnt;
	cin >> command_cnt;
	while (command_cnt--) {
		char command;
		cin >> command;
		switch (command)
		{
			// 커서 가장 왼쪽 == st1이 empty, st2가 full
			// 커서 가장 오른쪽 == st1이 full, st2가 empty
		case 'L':
			if (false == st1.empty()) {
				st2.push(st1.top());
				st1.pop();
			}
			break;
		case 'D':
			if (false == st2.empty()) {
				st1.push(st2.top());
				st2.pop();
			}
			break;
		case 'B':
			if (false == st1.empty()) {
				st1.pop();
			}
			break;
		case 'P':
			char special;
			cin >> special;
			st1.push(special);
			break;
		}
	}
	string str;
	int size = st1.size();
	for (int i = 0; i != size; i++) {
		str += st1.top();
		st1.pop();
	}
	for (int i = str.size() - 1; i >= 0; i--) {
		printf("%c", str[i]);
	}
	size = st2.size();
	for (int i = 0; i != size; i++) {
		printf("%c", st2.top());
		st2.pop();
	}
	return 0;
}