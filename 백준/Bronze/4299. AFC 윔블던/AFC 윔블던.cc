#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
	int a, b;
	int sum, minus;
	cin >> sum >> minus;
	a = (sum + minus) / 2;
	b = (sum - minus) / 2;
	if (a < 0 || b < 0 || a + b != sum || a - b != minus) {
		cout << -1;
	}
	else {
		cout << a << ' ' << b;
	}
	return 0;
}