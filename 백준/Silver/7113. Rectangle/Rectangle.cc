#include <iostream>
using namespace std;

int cnt = 0;

void cut(int a, int b) {
	cnt++;
	if (a == b) {
		return;
	}
	if (a < b) {
		b -= a;
	}
	else {
		a -= b;
	}
	cut(a, b);
}

int main() {
	int a, b;
	cin >> a >> b;
	cut(a, b);
	printf("%d", cnt);
	return 0;
}