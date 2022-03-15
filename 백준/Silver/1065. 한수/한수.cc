#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

const bool hansoo(int num) {
	vector<int> nums;
	bool ret = false;
	while (num >= 1) {
		nums.push_back(num % 10);
		num /= 10;
	}	
	//항상 세 자리 수 이상
	for (int i = 0; i != nums.size() - 2; i++) {
		if (nums[i] - nums[i + 1] == nums[i + 1] - nums[i + 2]) {
			ret = true;
		}
		else {
			return false;
		}
	}
	return ret;
}

int main() {
	int n;
	cin >> n;
	if (n < 100) {
		cout << n;
	}
	else {
		int ans = 0;
		for (int i = 100; i <= n; i++) {
			if (hansoo(i)) {
				ans++;
			}
		}
		cout << ans + 99;
	}
	return 0;
}