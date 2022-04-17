#include <iostream>
#include <vector>
using namespace std;

vector<bool> isPrime(1000001, true);

void checkPrime(int n) {
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i < n; i++) {
		if (isPrime[i] == false) continue;
		for (int j = 2; i * j <= n; j++) {
			isPrime[i * j] = false;
		}
	}
}

void sumSplit(int n) {
	int cnt = 0;
	for (int i = 2; i <= n / 2; i++) {
		if (isPrime[i] && isPrime[n - i]) {
			cnt++;
		}
	}
	cout << cnt << '\n';
}

void solution() {
	int n;
	cin >> n;
	if (n == 0) return;
	sumSplit(n);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	checkPrime(1000000);

	int testCaseNum = 1;
	cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}