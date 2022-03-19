#include <iostream>
#include <vector>
#include <deque>
#include <string>
using namespace std;

void solution() {
	int t;
	cin >> t;
	while (t--) {
		string command;
		cin >> command;
		int n;
		cin >> n;
		deque<int> dq;
		string arr, tmp;
		cin >> arr;
		for (int i = 1; i != arr.size() - 1; i++) {
			if (arr[i] == ',') {
				dq.push_back(stoi(tmp));
				tmp = "";
			}
			else {
				tmp += arr[i];
			}
		}
		if (tmp != "") {
			dq.push_back(stoi(tmp));
		}

		bool error = false;
		bool reverseState = false;
		for (int i = 0; i != command.size(); i++) {
			if (command[i] == 'R') {
				reverseState = reverseState == false;
			}
			else if (command[i] == 'D') {
				if (dq.empty()) {
					error = true;
					break;
				}
				if (reverseState) { dq.pop_back(); }
				else { dq.pop_front(); }
			}
		}

		if (error) {
			cout << "error" << '\n';
		}
		else {
			cout << '[';
			if (reverseState) {
				for (int i = dq.size() - 1; i >= 0; i--) {
					cout << dq[i];
					if (i > 0) {
						cout << ',';
					}
				}
			}
			else {
				for (int i = 0; i != dq.size(); i++) {
					cout << dq[i];
					if (i < dq.size() - 1) {
						cout << ',';
					}
				}
			}
			cout << ']' << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}