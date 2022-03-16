#include <iostream>
#include <vector>
using namespace std;

void solution() {
	int t;
	cin >> t;
	int a = 0, b = 0, c = 0;
	if (t >= 300) {
		a = t / 300;
		t %= 300;
	}
	if (t >= 60) {
		b = t / 60;
		t %= 60;
	}
	if (t >= 10) {
		c = t / 10;
		t %= 10;
	}
	if (t > 0) {
		cout << -1;
		return;
	}
	cout << a << ' ' << b << ' ' << c;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}