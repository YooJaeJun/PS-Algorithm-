#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int a;
	vector<int> nums;
	for (int i = 0; i != 10; i++) {
		cin >> a;
		auto it = find(nums.begin(), nums.end(), a % 42);
		if (it == nums.end()) {
			nums.push_back(a % 42);
		}
	}
	cout << nums.size();
	return 0;
}