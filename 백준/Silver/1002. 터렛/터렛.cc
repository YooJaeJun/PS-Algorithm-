#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct circle {
	int x;
	int y;
	int r;
};
//sqrt는 부동소수점 오차 때문에 제곱해서 비교해보자
const int exp2(const int& x) {
	return x * x;
}
const int distance_sq(const int& x1, const int& y1, const int& x2, const int& y2) {
	return (y2 - y1) * (y2 - y1) + (x2 - x1) * (x2 - x1);
}
int main() {
	int t;
	cin >> t;
	circle c1;
	circle c2;
	for (int i = 0; i != t; i++) {
		cin >> c1.x >> c1.y >> c1.r >> c2.x >> c2.y >> c2.r;
		const int d_sq = distance_sq(c1.x, c1.y, c2.x, c2.y);
		//완전 동일
		if (c1.x == c2.x && c1.y == c2.y && c1.r == c2.r) {
			cout << -1 << endl;
		}
		//두 점
		else if (d_sq < exp2(c1.r + c2.r) && d_sq > exp2(abs(c1.r - c2.r))) {
			cout << 2 << endl;
		}
		//한 점 외접 & 내접
		else if (exp2(c1.r + c2.r) == d_sq || exp2(abs(c1.r - c2.r)) == d_sq) {
			cout << 1 << endl;
		} 
		//만나지 않는 3가지 경우: 외부 떨어짐, 큰 원에 포함되면서 떨어짐, 동심원
		else if (d_sq > exp2(c1.r + c2.r) || d_sq < exp2(abs(c1.r - c2.r)) || d_sq == 0) {
			cout << 0 << endl;
		}
	}
	return 0;
}