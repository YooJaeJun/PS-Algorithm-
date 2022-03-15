#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int m, n;
	cin >> m >> n;
	vector<bool> primes(n + 1, true);
	primes[1] = false;
	for (int i = 2; i <= n; i++) {
		
		if (primes[i]) {
			for (int j = i + i; j <= n; j += i) {
				primes[j] = false;
			}
		}
	}
	for (int i = m; i <= n; i++) {
		if (primes[i]) {
			cout << i << '\n';
		}
	}

	return 0;
}