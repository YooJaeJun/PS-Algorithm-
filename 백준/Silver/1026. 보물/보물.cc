#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// a의 max * b의 min 유도

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	for (int i = 0; i != n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i != n; i++) {
		scanf("%d", &b[i]);
	}
	int sum = 0;
	while (n--) {
		int maxIdxA = max_element(a.begin(), a.end()) - a.begin();
		int minIdxB = min_element(b.begin(), b.end()) - b.begin();
		sum += (a[maxIdxA] * b[minIdxB]);
		a.erase(a.begin() + maxIdxA);
		b.erase(b.begin() + minIdxB);
	}
	cout << sum;

	return 0;
}