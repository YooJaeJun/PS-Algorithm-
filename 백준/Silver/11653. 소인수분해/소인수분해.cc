#include <iostream>
#include <vector>
using namespace std;

void solution() {
	int n;
	cin >> n;
	while (true) {
		bool isDived = false;
		for (int i = 2; i <= n; i++) {
			if (n % i == 0) {
				cout << i << '\n';
				n /= i;
				isDived = true;
				break;
			}
		}
		if (isDived == false) {
			break;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}