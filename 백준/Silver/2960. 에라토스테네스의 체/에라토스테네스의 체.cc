#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;
vector<bool> isPrime;
int idx = 0;
vector<int> order;

void checkPrime() {
	isPrime[1] = false;
	if (isPrime.size() >= 3) { 
		isPrime[2] = true;
	}
	//int rootN = sqrt(n);

	for (int i = 2; i <= n; i++) {
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				isPrime[i] = false;
				break;
			}
		}
		
		if (isPrime[i]) {
			order[idx++] = i;
			for (int j = i + i; j <= n; j += i) {
				if (isPrime[j]) {
					isPrime[j] = false;
					order[idx++] = j;
				}
			}
		}
	}
}

void solution() {
	int k;
	cin >> n >> k;
	isPrime.resize(n + 1, true);
	order.resize(n + 2);
	checkPrime();
	cout << order[k - 1];
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}