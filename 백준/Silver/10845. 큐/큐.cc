#include <iostream>
#include <queue>
using namespace std;

int main() {
	int command_cnt;
	cin >> command_cnt;
	queue<int> q;
	while (command_cnt--) {
		string command;
		cin >> command;
		if (command == "push") {
			int num;
			cin >> num;
			q.push(num);
		}
		else if (command == "pop") {
			if (q.empty()) {
				printf("-1\n");
			}
			else {
				printf("%d\n", q.front());
				q.pop();
			}
		}
		else if (command == "size") {
			printf("%d\n", q.size());
		}
		else if (command == "empty") {
			printf("%d\n", q.empty());
		}
		else if (command == "front") {
			if (q.empty()) {
				printf("-1\n");
			}
			else {
				printf("%d\n", q.front());
			}
		}
		else if (command == "back") {
			if (q.empty()) {
				printf("-1\n");
			}
			else {
				printf("%d\n", q.back());
			}
		}
	}
	return 0;
}