#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
	int burger[3];
	int drink[2];
	cin >> burger[0] >> burger[1] >> burger[2];
	cin >> drink[0] >> drink[1];
	int min = burger[0] + drink[0];
	for (int i = 0; i != 3; i++) {
		for (int j = 0; j != 2; j++) {
			min = (burger[i] + drink[j] > min) ? min : burger[i] + drink[j];
		}
	}
	cout << min - 50;
	return 0;
}