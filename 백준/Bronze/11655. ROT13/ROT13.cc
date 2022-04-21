#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solution() {
	char s[101];
	cin.getline(s, 101);
	for (auto& ch : s) {
		if (ch >= 'a' && ch <= 'z') {
			if (ch + 13 > 'z') {
				ch = 'a' - 1 + (ch + 13 - 'z');
			}
			else {
				ch += 13;
			}
		}
		else if (ch >= 'A' && ch <= 'Z') {
			if (ch + 13 > 'Z') {
				ch = 'A' - 1 + (ch + 13 - 'Z');
			}
			else {
				ch += 13;
			}
		}
	}
	cout << s;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}