#include <iostream>
#include <vector>
using namespace std;

void solution() {
	int n;
	cin >> n;
	if (n) cout << "Leading the Way to the Future";
	else cout << "YONSEI";
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}