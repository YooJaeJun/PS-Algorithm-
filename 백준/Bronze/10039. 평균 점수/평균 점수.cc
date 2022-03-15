#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
	int ar[5];
	int sum = 0;
	for (int i = 0; i != 5; i++) {
		cin >> ar[i];
		if (ar[i] < 40) { ar[i] = 40; }
		sum += ar[i];
	}
	cout << sum / 5;

	return 0;
}