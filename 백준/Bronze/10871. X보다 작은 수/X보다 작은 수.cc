#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
	int n, x;
	cin >> n >> x;
	int input;
	for (int i = 0; i != n; i++) {
		cin >> input;
		if (input < x) {
			cout << input << ' ';
		}
	}
	return 0;
}