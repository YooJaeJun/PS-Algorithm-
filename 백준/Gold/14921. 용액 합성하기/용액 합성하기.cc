#include <bits/stdc++.h>
using namespace std;

void solution() {
	int n;
	cin >> n;
	vector<long long > v(n);
	for (int i = 0; i != n; i++) {
		cin >> v[i];
	}

	int start = 0, end = 0;
	long long minNum = 1e10;
	for (int i = 0; i != n - 1; i++) {
		if (minNum > abs(v[i] + v[i + 1])) {
			minNum = abs(v[i] + v[i + 1]);
			start = i;
			end = i + 1;
		}
	}

	long long sum = 1e10;
	int num1 = 0, num2 = 0;
	while (start >= 0 && end < v.size()) {
		if (abs(sum) > abs(v[start] + v[end])) {
			sum = v[start] + v[end];
			num1 = v[start];
			num2 = v[end];
		}

		if (v[start] + v[end] < 0) {
			end++;
		}
		else if (v[start] + v[end] > 0) {
			start--;
		}
		else {
			break;
		}
	}

	cout << num1 + num2;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}