#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solution() {
	int n;
	cin >> n;
	vector<int> v(n);
	vector<int> sums(n);
	for (int i = 0; i != n; i++) {
		cin >> v[i];
		sums[i] = v[i];
	}

	for (int i = 0; i != v.size(); i++) {
		for (int j = 0; j != i; j++) {
			if (v[i] > v[j]) {
				sums[i] = max(sums[i], sums[j] + v[i]);
			}
		}
	}

	cout << *max_element(sums.begin(), sums.end());
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}