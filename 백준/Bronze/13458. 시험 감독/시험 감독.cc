#include <iostream>
#include <vector>
using namespace std;

void solution() {
	long long n, b, c;
	cin >> n;
	vector<long long> a(n);
	for (int i = 0; i != n; i++) {
		cin >> a[i];
	}
	cin >> b >> c;
	long long cnt = 0;
	for (int i = 0; i != n; i++) {
		a[i] -= b;
		cnt++;
		if (a[i] <= 0) continue;
		cnt += a[i] % c == 0 ? a[i] / c : a[i] / c + 1;
	}
	cout << cnt;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	//cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}