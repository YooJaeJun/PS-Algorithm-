#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	vector<int> nums;
	nums.resize(t);
	for (int i = 0; i != t; ++i) {
		scanf("%d", &nums[i]);
	}
	sort(nums.begin(), nums.end());
	for (int i = 0; i != t; ++i) {
		printf("%d\n", nums[i]);
	}
	return 0;
}