#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void solution() {
	queue<int> q;
	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		if (s == "push") {
			int num;
			cin >> num;
			q.push(num);
		}
		else if (s == "pop") {
			if (q.empty()) { 
				cout << -1 << '\n';
				continue;
			}
			cout << q.front() << '\n';
			q.pop();
		}
		else if (s == "size") {
			cout << q.size() << '\n';
		}
		else if (s == "empty") {
			cout << (int)q.empty() << '\n';
		}
		else if (s == "front") {
			if (q.empty()) {
				cout << -1 << '\n';
				continue;
			}
			cout << q.front() << '\n';
		}
		else if (s == "back") {
			if (q.empty()) {
				cout << -1 << '\n';
				continue;
			}
			cout << q.back() << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}