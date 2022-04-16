#include <iostream>
#include <vector>
using namespace std;

bool isFactor(int n1, int n2) {
	return n2 % n1 == 0;
}

bool isMultiple(int n1, int n2) {
	return n1 % n2 == 0;
}

void solution() {
	while (1) {
		int n1, n2;
		cin >> n1 >> n2;
		if (n1 == 0 && n2 == 0) return;

		if (isFactor(n1, n2)) {
			cout << "factor" << '\n';
		}
		else if (isMultiple(n1, n2)) {
			cout << "multiple" << '\n';
		}
		else {
			cout << "neither" << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}