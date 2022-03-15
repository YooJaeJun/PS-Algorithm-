#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
	int l;	int p;
	scanf("%d %d", &l, &p);
	int a, b, c, d, e;
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
	printf("%d %d %d %d %d", a - l * p, b - l * p, c - l * p, d - l * p, e - l * p);
	return 0;
}