#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int A, B;
	vector<int> sum;
	while (scanf("%d %d", &A, &B) != EOF) {
		cout << A + B << endl;
	}
	return 0;
}