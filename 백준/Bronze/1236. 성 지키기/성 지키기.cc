#include <iostream>
#include <vector>
using namespace std;

void solution() {
	int n, m;
	cin >> n >> m;
	char nodes[50][50] = { 0, };

	for (int i = 0; i != n; i++) {
		for (int j = 0; j != m; j++) {
			cin >> nodes[i][j];
		}
	}

	int i = 0, j = 0;
	int cnt1 = 0, cnt2 = 0;

	for (int i = 0; i != n; i++) {
		bool isPat = false;
		for (int j = 0; j != m; j++) {
			if (nodes[i][j] == 'X') {
				isPat = true;
				break;
			}
		}
		if (isPat == false) cnt1++;
	}
	for (int i = 0; i != m; i++) {
		bool isPat = false;
		for (int j = 0; j != n; j++) {
			if (nodes[j][i] == 'X') {
				isPat = true;
				break;
			}
		}
		if (isPat == false) cnt2++;
	}
	cout << max(cnt1, cnt2);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}