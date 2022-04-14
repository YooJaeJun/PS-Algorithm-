#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

double cross(double x1, double y1, double x2, double y2, double x3, double y3) {
	return (x1 * y2 + x2 * y3 + x3 * y1 
		- (x2 * y1 + x3 * y2 + x1 * y3)) 
		/ 2;
}

void solution() {
	int n;
	scanf("%d", &n);
	vector<pair<double, double>> v(n);
	for (int i = 0; i != n; i++) {
		scanf("%lf %lf", &v[i].first, &v[i].second);
	}

	double ans = 0.0f;
	for (int i = 1; i != n - 1; i++) {
		ans += cross(v[0].first, v[0].second, v[i].first, v[i].second, v[i + 1].first, v[i + 1].second);
	}
	printf("%.1lf", abs(ans));
}

int main() {
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}