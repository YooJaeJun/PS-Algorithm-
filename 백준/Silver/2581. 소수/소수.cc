#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int m, n;
vector<bool> isPrime;

void checkPrime() {
	isPrime[1] = false;
	if (isPrime.size() >= 3) { isPrime[2] = true; }
	int rootN = sqrt(n);

	for (int i = 2; i <= rootN; i++) {
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

void solution() {
	cin >> m >> n;
	isPrime.resize(n + 1, true);
	checkPrime();
	bool isFirst = true;
	int sum = 0, min = 0;
	for (int i = m; i <= n; i++) {
		if (isPrime[i]) {
			if (isFirst) { 
				min = i; 
				isFirst = false;
			}
			sum += i;
		}
	}
	if (sum == 0) { cout << -1; }
	else { cout << sum << '\n' << min; }
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}