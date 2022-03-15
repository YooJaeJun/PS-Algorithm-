#include <iostream>
#include <vector>
using namespace std;

void solution() {
	int n;
	cin >> n;

	for (int i = 0; i != n; i++) {
		for (int j = 0; j < i; j++) {
			cout << ' ';
		}
		for (int j = 2 * (n - i - 1) + 1; j > 0; j--) {
			cout << '*';
		}
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}