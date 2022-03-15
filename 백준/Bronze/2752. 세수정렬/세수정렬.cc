#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> nums(3);
	for (int& n : nums) {
		cin >> n;
	}
	sort(nums.begin(), nums.end());
	for (int& n : nums) {
		cout << n << ' ';
	}
	return 0;
}