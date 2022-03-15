#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;
	int n;
	for (int i = 0; i != t; i++) {
		cin >> n;
		string bin_reverse;
		while (true) {
			if (n == 1) {
				bin_reverse += to_string(n);
				break;
			}
			else if (!(n % 2)) {
				bin_reverse += '0';
			}
			else {
				bin_reverse += '1';
			}
			n /= 2;
		}
		for (int j = 0; j != bin_reverse.size(); j++) {
			if (bin_reverse[j] == '1') {
				cout << j << ' ';
			}
		}
		puts("");
	}
	return 0;
}