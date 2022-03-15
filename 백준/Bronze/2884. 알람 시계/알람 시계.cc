#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
	int h, m;
	cin >> h >> m;
	if (m >= 45) {
		cout << h << ' ' << m - 45;
	}
	else {
		if (h == 0) {
			cout << 23 << ' ' << 60 + m - 45;
		}
		else {
			cout << h - 1 << ' ' << 60 + m - 45;
		}
	}
	return 0;
}