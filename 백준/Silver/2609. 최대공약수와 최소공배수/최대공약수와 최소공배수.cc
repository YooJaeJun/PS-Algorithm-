#include <iostream>
using namespace std;

int gcd(int n1, int n2) {
	int gcd = 1;
	for (int i = 1; i <= n1 && i <= n2; i++) {
		if (n1 % i == 0 && n2 % i == 0) {
			gcd = i;
		}
	}
	return gcd;
}

int lcm(int n1, int n2) {
	return (n1 * n2) / gcd(n1, n2);
}

int main() {
	int n1, n2;
	cin >> n1 >> n2;
	printf("%d\n%d", gcd(n1, n2), lcm(n1, n2));

	return 0;
}