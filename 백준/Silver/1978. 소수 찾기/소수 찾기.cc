#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i != n; i++) {
		int num;
		scanf("%d", &num);
		bool isPrime = true;
		if (num == 1) { isPrime = false; }
		for (int j = 2; j < num; j++) {
			if (num % j == 0) {
				isPrime = false;
				break;
			}
		}
		ans += isPrime;
	}
	cout << ans;

	return 0;
}