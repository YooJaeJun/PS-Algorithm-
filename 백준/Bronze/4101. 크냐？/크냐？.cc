#include <iostream>
#include <vector>
using namespace std;

void solution() {
	while (1) {
		int n1, n2;
		cin >> n1 >> n2;
		if (n1 == 0 && n2 == 0) break;
		if (n1 > n2) cout << "Yes" << '\n';
		else cout << "No" << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	//cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}