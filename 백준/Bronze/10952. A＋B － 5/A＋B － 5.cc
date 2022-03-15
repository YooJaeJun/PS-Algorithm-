#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int a, b;
	vector<int> sum;
	while(true) {
		cin >> a;
		cin >> b;
		if (a == 0 && b == 0) {
			break;
		}
		else {
			cout << a + b << endl;
		}
	}
	return 0;
}