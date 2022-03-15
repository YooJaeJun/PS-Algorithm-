#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int total;
	scanf("%d", &total);
	vector<int> nums;
	for (int i = 0; i != total; i++) {
		nums.push_back(0);
		scanf("%d", &nums[i]);
	}
	printf("%d %d", *min_element(nums.begin(), nums.end()), *max_element(nums.begin(), nums.end()));
	return 0;
}