#include <iostream>
#include <vector>
using namespace std;

int gcd(int n1, int n2) {
	int m = min(n1, n2);
	int ret = 1;
	for (int i = 2; i <= m; i++) {
		if (n1 % i == 0 && n2 % i == 0) {
			ret = i;
		}
	}
	return ret;
}

int lcm(int n1, int n2) {
	return (n1 * n2) / gcd(n1, n2);
}

void solution() {
	int t;
	cin >> t;
	while (t--) {
		int n1, n2;
		cin >> n1 >> n2;
		cout << lcm(n1, n2) << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}