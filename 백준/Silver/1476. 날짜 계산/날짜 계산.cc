#include <iostream>
#include <vector>
using namespace std;

void solution() {
	int e, s, m;
	cin >> e >> s >> m;
	for (int i = 1;; i++) {

		int y1 = i % 15;
		int y2 = i % 28;
		int y3 = i % 19;
		if (y1 == 0) y1 = 15;
		if (y2 == 0) y2 = 28;
		if (y3 == 0) y3 = 19;

		if (y1 == e && y2 == s && y3 == m) {
			cout << i;
			return;
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