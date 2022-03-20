#include <iostream>
#include <vector>
using namespace std;

void solution() {
	int sum = 0;
	vector<int> nums(10);
	for (int i = 0; i != 10; i++) {
		cin >> nums[i];
	}
	for (int i = 0; i != 10; i++) {
		sum += nums[i];
		if (sum >= 100) {
			if (sum - 100 > 100 - (sum - nums[i])) {
				sum -= nums[i];
				break;
			}
			else {
				break;
			}
		}
	}
	cout << sum;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}