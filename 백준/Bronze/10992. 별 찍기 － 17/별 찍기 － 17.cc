#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n - i; j++) {
			printf(" ");
		}
		if (i == 1) {
			printf("*");
		}
		else if (i != n) {
			printf("*");
			for (int j = 1; j <= (i - 2) * 2 + 1; j++) {
				printf(" ");
			}
			printf("*");
		}
		else {
			for (int j = 1; j <= n * 2 - 1; j++) {
				printf("*");
			}
		}
		printf("\n");
	}
	return 0;
}