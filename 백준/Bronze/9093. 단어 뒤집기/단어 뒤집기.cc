#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

void solution() {
	char s[1001];
	cin.getline(s, 1001, '\n');
	int size = strlen(s);
	string splited;

	for (int i = 0; i <= size; i++) {
		if (s[i] == ' ' || s[i] == '\0') {
			for (int i = splited.size() - 1; i >= 0; i--) {
				cout << splited[i];
			}
			cout << ' ';
			splited = "";
		}
		else {
			splited += s[i];
		}
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	cin >> testCaseNum;
	cin.ignore();
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}