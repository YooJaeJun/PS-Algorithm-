#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long long n, m;
	scanf("%lld %lld", &n, &m);
	printf("%lld", abs(n - m));
	return 0;
}