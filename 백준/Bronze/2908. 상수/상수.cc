#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main() {
	string input_s1, input_s2;
	cin >> input_s1 >> input_s2;
	string s1, s2;
	for (int i = input_s1.size() - 1; i >= 0; i--) {
		s1 += input_s1[i];
		s2 += input_s2[i];
 	}
	if (stoi(s1) >= stoi(s2)) {
		cout << s1;
	}
	else {
		cout << s2;
	}

	return 0;
}