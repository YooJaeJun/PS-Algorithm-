#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int p = 2;
	for (int i = 2; i <= n; i++) {
		p += i / 2 + 1;
	}
	cout << p;
	return 0;
}