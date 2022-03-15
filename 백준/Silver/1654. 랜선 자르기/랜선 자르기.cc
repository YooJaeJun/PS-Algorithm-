#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int k, n;
	cin >> k >> n;
	long long max = 0;
	vector<int> nums(k);
	for (int i = 0; i != k; i++) {
		cin >> nums[i];
		max = max < nums[i] ? nums[i] : max;
	}

	long long start = 1;
	long long end = max;
	while (start <= end) {
		long long mid = (start + end) / 2;
		long long cnt = 0;

		for (int i = 0; i != nums.size(); i++) {
			cnt += (nums[i] / mid);
		}

		if (cnt < n) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}

	cout << end;

	return 0;
}