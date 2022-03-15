#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;
	float n;
	for (int i = 0; i != t; i++) {
		cin >> n;
		vector<int> scores;
		float sum = 0;
		float input;
		for (int j = 0; j != n; j++) {
			cin >> input;
			scores.push_back(input);
			sum += input;
		}
		float av = sum / n;
		float idx = 0;
		for (const auto& elem : scores) {
			if (elem > av) {
				idx++;
			}
		}
		printf("%.3f\%\n", idx / n * 100);
	}
	return 0;
}