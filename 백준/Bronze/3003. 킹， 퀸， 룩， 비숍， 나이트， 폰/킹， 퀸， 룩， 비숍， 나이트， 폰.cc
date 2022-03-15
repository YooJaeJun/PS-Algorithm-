#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
	//킹 1개, 퀸 1개, 룩 2개, 비숍 2개, 나이트 2개, 폰 8개
	int chess[6] = { 1, 1, 2, 2, 2, 8 };
	int n;
	for (int i = 0; i != 6; i++) {
		cin >> n;
		cout << chess[i] - n << ' ';
	}
	return 0;
}