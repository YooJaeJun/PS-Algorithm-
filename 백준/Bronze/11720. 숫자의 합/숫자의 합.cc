#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int total;
	cin >> total;
	string s;
	int sum = 0;
	for (int i = 0; i != total; i++) {
		s.push_back(0);
	}
	getchar();
	getline(cin, s);
	for (int i = 0; i != total; i++) {
		sum += s[i] - '0';
	}
	cout << sum;
	return 0;
}