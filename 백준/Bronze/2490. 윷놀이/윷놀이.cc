#include <iostream>
#include <vector>
using namespace std;

void solution() {
	for (int i = 0; i != 3; i++) {
		int cntBae = 0, cntDng = 0;
		for (int i = 0; i != 4; i++) {
			int num;
			cin >> num;
			if (num == 0) {
				cntBae++;
			}
			else {
				cntDng++;
			}
		}
		char c = cntDng == 4 ? 'E' : 'A' + cntBae - 1;
		cout << c << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	//cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}