#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int size;
	cin >> size;
	vector<int> nums(size);
	for (int i = 0; i != size; i++) {
		cin >> nums[i];
	}
	map<int, int> m;
	vector<int> sort_nums = nums;
	//정렬한 벡터 순서가 곧 순위 반대 -> 맵의 값에 넣는다. -> 동점 처리
	sort(sort_nums.begin(), sort_nums.end());
	for (int i = 0; i != sort_nums.size() - 1; i++) {
		if (sort_nums[i] != sort_nums[i + 1]) {
			m[sort_nums[i]] = size - i;
		}
		else {
			m[sort_nums[i]] = m[sort_nums[i + 1]] = size - i - 1;
			i++;
		}
	}
	m[sort_nums[size - 1]] = 1;

	for (const int& elem : nums) {
		cout << elem << ' ' << m[elem] << endl;
	}
	return 0;
}