#include <iostream>
#include <vector>
using namespace std;

void f(int n) {
}

void solution() {
	int n;
	cin >> n;

	for (int i = 2; i <= n / 2; i += 2) {
		if (i % 2 == 0 && (n - i) % 2 == 0) {
			cout << "YES";
			return;
		}
	}
	cout << "NO";
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}