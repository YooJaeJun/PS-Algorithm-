#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int a, b, v;
	cin >> a >> b >> v;
	double day = (double)(v - a) / (a - b) + 1;	// a1 + d(day - 1) >= v
	cout << (int)ceil(day);
	return 0;
}