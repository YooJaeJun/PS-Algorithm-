#include <iostream>
#include <vector>
using namespace std;

int l, r;

void infinity(int a, int b) {
	while (true) {
		if (a == 1) {
			r += b - 1;
			break;
		}
		else if (b == 1) {
			l += a - 1;
			break;
		}
		if (a > b) {
			l += a / b;
			a %= b;
		}
		else if (a < b) {
			r += b / a;
			b %= a;
		}
	}
}

int main() {
	int a, b;
	cin >> a >> b;
	infinity(a, b);
	cout << l << ' ' << r;
	return 0;
}