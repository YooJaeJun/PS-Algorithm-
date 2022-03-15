#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
	int x;
	cin >> x;
	if (x == 1) {
		cout << 1;
	}
	else if (x >= 2 && x <= 7) {
		cout << 2;
	}
	else {
		for (int i = 1;; i++) {
			int sum = 3 * i * (i + 1);		//첫항6, 공차 6인 등차수열의 합을 풀어쓴 것. (i(2a+(i-1)d))/2
			int sum_next = 3 * (i + 1) * (i + 2);
			if (x >= 2 + sum && x < 2 + sum_next) {	//규칙성상 2 + 등차수열합으로 범위 판단
				cout << i + 2;	//칸 수 보정
				break;
			}
		}
	}
	return 0;
}