#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double whoMax(double n1, double n2, double n3, double n4) {
	return max(n1, max(n2, max(n3, n4)));
}

bool intersectWithSameLine(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
	// 같은 직선 위에 있는지 판단: ac,ad,bc,bd 선분 중 max 값이 ab+cd보다 크면 안 만남
	double ac = sqrtl((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
	double ad = sqrtl((x4 - x1) * (x4 - x1) + (y4 - y1) * (y4 - y1));
	double bc = sqrtl((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
	double bd = sqrtl((x4 - x2) * (x4 - x2) + (y4 - y2) * (y4 - y2));
	double ab = sqrtl((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	double cd = sqrtl((x4 - x3) * (x4 - x3) + (y4 - y3) * (y4 - y3));

	double maxNum = whoMax(ac, ad, bc, bd);
	return maxNum < ab + cd ||
		fabs(maxNum - (ab + cd)) < 1e-10;
}

double ccw(double x1, double y1, double x2, double y2, double x3, double y3) {
	return x1 * y2 + x2 * y3 + x3 * y1 -
		(y1 * x2 + y2 * x3 + y3 * x1);
}

bool intersect(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
	if (ccw(x1, y1, x2, y2, x3, y3) * ccw(x1, y1, x2, y2, x4, y4) == 0 &&
		ccw(x3, y3, x4, y4, x1, y1) * ccw(x3, y3, x4, y4, x2, y2) == 0) {
		return intersectWithSameLine(x1, y1, x2, y2, x3, y3, x4, y4);
	}
	return ccw(x1, y1, x2, y2, x3, y3) * ccw(x1, y1, x2, y2, x4, y4) <= 0 &&
		ccw(x3, y3, x4, y4, x1, y1) * ccw(x3, y3, x4, y4, x2, y2) <= 0;
}

void solution() {
	double x1, y1, x2, y2, x3, y3, x4, y4;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	cout << intersect(x1, y1, x2, y2, x3, y3, x4, y4);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}