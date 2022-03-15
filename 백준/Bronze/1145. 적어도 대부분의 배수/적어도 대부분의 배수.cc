#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int n1, int n2) {
	int gcd;
	for (int i = 1; i <= n1 && i <= n2; i++) {
		if (n1 % i == 0 && n2 % i == 0) {
			gcd = i;
		}
	}
	return gcd;
}

int lcm(int n1, int n2) {
	return (n1 * n2) / gcd(n1, n2);
}

int calculate(int n1, int n2, int n3) {
	return lcm(lcm(n1, n2), n3);
}

int main() {
	vector<int> inputs(5);
	for (int i = 0; i != 5; i++) {
		scanf("%d", &inputs[i]);
	}
	vector<int> lcms;
	for (int i = 0; i != 3; i++) {
		for (int j = i + 1; j != 4; j++) {
			for (int k = j + 1; k != 5; k++) {
				lcms.push_back(calculate(inputs[i], inputs[j], inputs[k]));
			}
		}
	}
	printf("%d", *min_element(lcms.begin(), lcms.end()));

	return 0;
}