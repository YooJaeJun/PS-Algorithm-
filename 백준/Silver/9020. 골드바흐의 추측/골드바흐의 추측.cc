#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int limit = 10000 * 2;
vector<bool> isPrime(limit + 1, true);

void checkPrime() {
	isPrime[0] = false;
	isPrime[1] = false;
	for (int i = 2; i < limit; i++) {
		if (isPrime[i] == false) { continue; }
		for (int j = 2; j * i <= limit; j++) {
			isPrime[j * i] = false;
		}
	}
}

void solution() {
	checkPrime();
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = n / 2; i >= 0; i--) {
			if (isPrime[i] && 
				isPrime[n - i]) {
				cout << i << ' ' << n - i << '\n';
				break;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}