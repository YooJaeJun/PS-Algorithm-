#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<bool> isPrime(1000001, true);

void checkPrime(int n) {
	isPrime[0] = isPrime[1] = false;
	int sq = sqrt(n);
	for (int i = 3; i <= sq; i++) {
		if (isPrime[i] == false) continue;

		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				isPrime[i] = false;
				break;
			}
		}
		if (isPrime[i]) {
			for (int j = i + i; j <= n; j += i) {
				isPrime[j] = false;
			}
		}
	}
}

void sumSplit(int n) {
	for (int i = 3; i < n; i++) {
		if (isPrime[i] && isPrime[n - i]) {
			cout << n << " = " << i << " + " << n - i << '\n';
			return;
		}
	}

	cout << "Goldbach's conjecture is wrong.";
}

void solution() {
	checkPrime(1000000);
	while (1) {
		int n;
		cin >> n;
		if (n == 0) return;
		sumSplit(n);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}