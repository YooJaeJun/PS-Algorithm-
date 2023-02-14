#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solution() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i != n; i++) {
		cin >> v[i];
	}

	for (int i = 2; i != n; i++) {
		if (i % 2 == 0 && v[0] % 2 != v[i] % 2) {
			cout << "NO" << '\n';
			return;
		}
		if (i % 2 == 1 && v[1] % 2 != v[i] % 2) {
			cout << "NO" << '\n';
			return;
		}
	}
	cout << "YES" << '\n';
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}