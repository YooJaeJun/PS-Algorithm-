#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> maxs;
	for (int i = 0; i != n; i++) {
		vector<int> nums(5);
		for (int j = 0; j != 5; j++) {
			scanf("%d", &nums[j]);
		}
		int max = -1;
		for (int i = 0; i < 3; i++) {
			for (int j = i + 1; j < 4; j++) {
				for (int k = j + 1; k < 5; k++) {
					int num = (nums[i] + nums[j] + nums[k]) % 10;
					max = (max < num) ? num : max;
				}
			}
		}
		maxs.push_back(max);
	}
	int max = maxs[0];
	int maxIdx = 0;
	for (int i = 1; i != maxs.size(); i++) {
		if (max < maxs[i]) {
			maxIdx = i;
			max = maxs[i];
		}
		else if (max == maxs[i]) {
			if (maxIdx <= i) {
				maxIdx = i;
			}
		}
	}
	printf("%d", maxIdx + 1);

	return 0;
}