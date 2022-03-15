#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	b += c;
	int max = b;
	if (b >= 60) {
		for (int i = 0; i != max / 60; i++) {
			b -= 60;
			a++;
			if (a >= 24) {
				a = 0;
			}
		}
	}
	cout << a << ' ' << b;
	return 0;
}