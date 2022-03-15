#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	while (1) {
		vector<int> nums(3);
		scanf("%d %d %d", &nums[0], &nums[1], &nums[2]);
		if (nums[0] == 0 && nums[1] == 0 && nums[2] == 0) {
			break;
		}
		int sum = 0;
		int max = *max_element(nums.begin(), nums.end());
		for (auto& elem : nums) {
			if (elem != max) {
				sum += elem * elem;
			}
		}
		if (sum == max * max) {
			printf("right\n");
		}
		else {
			printf("wrong\n");
		}
	}

	return 0;
}