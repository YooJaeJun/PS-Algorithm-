#include <iostream>
#include <vector>
using namespace std;

void solution() {
	const int siz = 15, line = 5;
	char arr[15][15] = { '.', };
	for (int i = 0; i != line; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i != siz; i++) {
		for (int j = 0; j != siz; j++) {
			if (arr[j][i] != NULL) {
				cout << arr[j][i];
			}
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