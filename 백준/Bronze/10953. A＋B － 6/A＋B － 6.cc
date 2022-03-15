#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int a, b, total;
	char sign = ',';
	cin >> total;
	for (int i = 0; i != total; i++) {
		scanf("%d", &a);
		scanf("%c", &sign);
		scanf("%d", &b);
		printf("%d\n", a + b);
	}
	return 0;
}