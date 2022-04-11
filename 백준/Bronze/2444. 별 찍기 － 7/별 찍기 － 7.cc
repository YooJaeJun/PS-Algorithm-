#include <iostream>
#include <vector>
using namespace std;

void solution() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = n - 1 - i; j > 0; j--) {
			cout << ' ';
		}
		for (int j = 0; j < i * 2 + 1; j++) {
			cout << '*';
		}
		cout << '\n';
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j <= i; j++) {
			cout << ' ';
		}
		for (int j = 2 * (n - 1) - 1 - (i * 2); j > 0; j--) {
			cout << '*';
		}
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}