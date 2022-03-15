#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	int sum = 0;
	int n = 0;
	for (const int& elem : s) {
		n = (elem - 'A') / 3;
		if (elem == 'S' || elem == 'V' || elem == 'Y' || elem == 'Z') {
			n++;
		}
		else {
			n += 2;
		}
		sum += n + 1;
	}
	cout << sum;
	return 0;
}