#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solution() {
	int n;
	cin >> n;
	vector<int> v(n);
	vector<int> dpIncrease(n);
	vector<int> dpDecrease(n);
	for (int i = 0; i != n; i++) {
		cin >> v[i];
		dpIncrease[i] = 1;
	}

	for (int i = 0; i != v.size(); i++) {	// 앞부터 증
		for (int j = 0; j != i; j++) {
			if (v[i] > v[j]) {
				dpIncrease[i] = max(dpIncrease[i], dpIncrease[j] + 1);
			}
		}
	}

	for (int i = v.size() - 1; i >= 0; i--) {	// 뒤부터 증
		for (int j = v.size() - 1; j != i; j--) {
			if (v[i] > v[j]) {
				dpDecrease[i] = max(dpDecrease[i], dpDecrease[j] + 1);
			}
		}
	}

	// 이어붙이기
	for (int i = 0; i != v.size(); i++) {
		dpIncrease[i] += dpDecrease[i];
	}

	cout << *max_element(dpIncrease.begin(), dpIncrease.end());
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}