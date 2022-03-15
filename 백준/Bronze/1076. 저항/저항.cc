#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	vector<string> color = {
		"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white"
	};
	string c1, c2, c3;
	cin >> c1 >> c2 >> c3;
	long long c1_value = 0; long long c2_value = 0; long long c3_tmp = 0;
	for (int i = 0; i != color.size(); ++i) {
		if (color[i] == c1) { c1_value = i;	}
		if (color[i] == c2) { c2_value = i; }
		if (color[i] == c3) { c3_tmp = i; }
	}
	long long c3_value = 1;
	if (c3_tmp != 0) {
		for (int i = 1; i <= c3_tmp; ++i) {
			c3_value *= 10;
		}
	}
	c1_value *= c3_value * 10;
	c2_value *= c3_value;
	printf("%lld", c1_value + c2_value);
	return 0;
}