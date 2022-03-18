#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solution() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i != n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	vector<int> sums(n);
	for (int i = 0; i != v.size(); i++) {
		for (int j = 0; j <= i; j++) {
			sums[i] += v[j];
		}
	}
	int sumsum = 0;
	for (auto& elem : sums) {
		sumsum += elem;
	}
	cout << sumsum;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}