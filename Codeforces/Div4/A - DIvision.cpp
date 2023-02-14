#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solution() {
	int n;
	cin >> n;
	if (n >= 1900) {
		cout << "Division 1" << '\n';
	}
	else if (n >= 1600 && n <= 1899) {
		cout << "Division 2" << '\n';
	}
	else if (n >= 1400 && n <= 1599) {
		cout << "Division 3" << '\n';
	}
	else {
		cout << "Division 4" << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}