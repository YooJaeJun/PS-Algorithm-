#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define M_PI 3.14159265358979323846

void solution() {
	float r;
	cin >> r;
	printf("%.6f\n%.6f", (double)r * r * M_PI, (double)r * (double)r * 2.0f);
}

int main() {
	solution();
	return 0;
}