#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int a, b, total;
	cin >> total;
	for (int i = 0; i != total; i++) {
		scanf("%d %d", &a, &b);
		printf("Case #%d: %d\n", i + 1, a + b);
	}
	return 0;
}