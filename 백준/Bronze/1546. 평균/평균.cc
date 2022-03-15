#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	float t;
	cin >> t;
	vector<float> v;
	int input;
	for (int i = 0; i != t; i++) {
		cin >> input;
		v.push_back(input);
	}
	float m = *max_element(v.begin(), v.end());
	float sum = 0;
	for (auto& elem : v) {
		elem = elem / m * 100;
		sum += elem;
	}
	printf("%g", sum / t);
	return 0;
}