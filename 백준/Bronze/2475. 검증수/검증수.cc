#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
	char c;
	string s;
	for (int i = 0; i != 5; i++) {
		cin >> c;
		s += c;
	}
	int num = 0;
	int sum = 0;
	for (const int& elem : s) {
		num = elem - '0';
		sum += num * num;
	}
	printf("%d", sum % 10);
	return 0;
}