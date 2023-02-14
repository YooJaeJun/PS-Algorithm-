#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solution() {
	int n;
	cin >> n;
	vector<int> v(n + 1);
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v[num]++;
	}

	for (int i = 0; i <= n; i++) {
		if (v[i] >= 3) {
			cout << i << '\n';
			return;
		}
	}
	cout << -1 << '\n';
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}