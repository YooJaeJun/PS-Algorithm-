#include <iostream>
#include <vector>
using namespace std;

void solution() {
	int m, n;
	cin >> m >> n;
	int sum = 0, minimum = 0;
	for (int i = 1; i <= 100; i++) {
		if (i * i >= m && i * i <= n) {
			if (sum == 0) {
				minimum = i * i;
			}
			sum += i * i;
		}
		if (i * i > n) {
			break;
		}
	}
	if (sum == 0) {
		cout << -1;
	}
	else {
		cout << sum << '\n' << minimum;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}