#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
	int l, a, b, c, d;
	cin >> l >> a >> b >> c >> d;
	int aday, bday;
	aday = a / c;
	if (a % c) {
		aday++;
	}
	bday = b / d;
	if (b % d) {
		bday++;
	}
	cout << l - max(aday, bday);
	return 0;
}