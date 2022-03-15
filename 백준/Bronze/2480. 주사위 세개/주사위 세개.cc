#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int sum = 0;
	if (a == b && b == c && a == c) {
		printf("%d", 10000 + a * 1000);
	}
	else if (a == b || b == c) {
		printf("%d", 1000 + b * 100);
	}
	else if (a == c) {
		printf("%d", 1000 + a * 100);
	}
	else {
		int max = a;
		max = (max > b ? max : b);
		max = (max > c ? max : c);
		printf("%d", max * 100);
	}
	return 0;
}