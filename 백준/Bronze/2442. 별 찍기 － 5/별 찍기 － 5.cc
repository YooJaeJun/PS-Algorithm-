#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = n; j > i; j--) {
			printf(" ");
		}
		for (int j = 1; j <= i * 2 - 1; j++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}