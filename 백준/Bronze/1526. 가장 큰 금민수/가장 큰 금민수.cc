#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solution() {
	int n;
	cin >> n;
	string s;
	for (int i = n; i >= 4; i--) {
		s = to_string(i);
		bool isAns = true;
		for (auto& elem : s) {
			if (elem != '4' && elem != '7') {
				isAns = false;
				break;
			}
		}
		if (isAns) {
			cout << i;
			return;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	//cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}