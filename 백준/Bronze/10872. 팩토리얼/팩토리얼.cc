#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int factorial(int n) {
	if (n <= 1) { return 1; }
	int sum = n--;
	return sum * factorial(n);
}
int main() {
	int n;
	cin >> n;
	cout << factorial(n);
	return 0;
}