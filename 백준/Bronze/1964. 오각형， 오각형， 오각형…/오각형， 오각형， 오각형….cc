#include <bits/stdc++.h>
using namespace std;

void solution() {
	int n;
	cin >> n;
	long long x = 5, coef = 7;
	for (int i = 1; i != n; i++) {
		x += coef;
		coef += 3;
		x %= 45678;
	}
	cout << x;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}