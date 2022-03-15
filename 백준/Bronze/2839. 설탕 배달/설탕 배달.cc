#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	if (n % 5 == 0) {
		cout << n / 5;
		return 0;
	}
	for (int i = n / 5; i > 0; i--) {
		for (int j = 1; j <= n / 3; j++) {
			if (n - (5 * i) == 3 * j) {
				cout << i + j;
				return 0;
			}
			else if (n - (5 * i) < 3 * j) {
				break;
			}
		}
	}
	if (n % 3 == 0) {
		cout << n / 3;
		return 0;
	}

	cout << -1;

	return 0;
}