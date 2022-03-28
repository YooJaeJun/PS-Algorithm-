#include <iostream>
#include <vector>
using namespace std;

void solution() {
	int n;
	cin >> n;
	for (int i = 0; i != n; i++) {
		for (int j = i; j < n - 1; j++) {
			cout << ' ';
		}
		cout << '*';
		for (int j = 0; j < i * 2 - 1; j++) {
			cout << ' ';
		}

		if (i != 0) {
			cout << '*';
		}
		if (i != n - 1) {
			cout << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}