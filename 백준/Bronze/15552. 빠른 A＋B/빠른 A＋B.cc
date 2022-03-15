#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	int a, b;
	for (int i = 0; i != t; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", a + b);
	}
	return 0;
}