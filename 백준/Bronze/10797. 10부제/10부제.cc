#include <iostream>
#include <vector>

using namespace std;

int main() {
	int day;
	vector<int> nums(5);
	cin >> day;
	int cnt = 0;
	for (auto& num : nums) {
		cin >> num;
		cnt = num == day ? cnt + 1 : cnt;
	}
	cout << cnt;
}