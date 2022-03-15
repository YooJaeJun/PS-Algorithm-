#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if (b < c && c != b) {
		cout << a / (c - b) + 1;
	}
	else {
		cout << -1;
	}
	return 0;
}