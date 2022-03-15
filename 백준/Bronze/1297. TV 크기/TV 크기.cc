#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double d;	double h;	double w;
	scanf("%lf %lf %lf", &d, &h, &w);
	double h_ = sqrt(d * d / (h * h + w * w)) * h;
	double w_ = sqrt(d * d / (h * h + w * w)) * w;
	printf("%d %d", static_cast<int>(h_), static_cast<int>(w_));
	return 0;
}