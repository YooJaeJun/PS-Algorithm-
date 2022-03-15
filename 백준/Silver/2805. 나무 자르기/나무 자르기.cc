#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	long long n, m;
	cin >> n >> m;
	vector<int> v(n);
	for(int i = 0; i != n; i++) {
		cin >> v[i];
	}
	
	long long max = *max_element(v.begin(), v.end());
	long long start = 0;
	long long end = max;

	// 이분 탐색
	while (start <= end) {
		long long mid = (start + end) / 2;
		long long sum = 0;
		for (auto& elem : v) {
			if (elem > mid) {
				sum += elem - mid;
			}
		}
		if (sum < m) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	cout << end;

	return 0;
}