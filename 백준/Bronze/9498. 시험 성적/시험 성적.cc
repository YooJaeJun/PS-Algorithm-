#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
	int s;
	cin >> s;
	if (s >= 90 && s <= 100) {
		cout << "A";
	}
	else if (s >= 80 && s <= 89) {
		cout << "B";
	}
	else if (s >= 70 && s <= 79) {
		cout << "C";
	}
	else if (s >= 60 && s <= 69) {
		cout << "D";
	}
	else {
		cout << "F";
	}
	return 0;
}