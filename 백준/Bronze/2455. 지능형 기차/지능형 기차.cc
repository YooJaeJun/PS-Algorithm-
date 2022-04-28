#include <bits/stdc++.h>
using namespace std;

void solution() {
	int maxNum = 0, human = 0;
	for (int i = 0; i != 4; i++) {
		int m, p;
		cin >> m >> p;
		human -= m;
		human += p;
		maxNum = max(maxNum, human);
	}
	cout << maxNum;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}