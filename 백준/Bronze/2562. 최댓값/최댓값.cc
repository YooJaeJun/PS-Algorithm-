#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
	int nums[9];
	int max = 0;
	int idx = 0;
	for (int i = 0; i != 9; i++) {
		scanf("%d", &nums[i]);
		if (max < nums[i]) {
			max = nums[i];
			idx = i;
		}
	}
	cout << max << endl << idx + 1;
	return 0;
}