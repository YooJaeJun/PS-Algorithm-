#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

const int maxNum = 1003001;	// 100만 이상이면서 조건 만족
vector<bool> isPrime(maxNum + 1, true);

void checkPrime() {
	isPrime[0] = false;
	isPrime[1] = false;

	int maxSq = sqrt(maxNum);
	for (int i = 2; i <= maxSq; i++) {
		// 반환
		if (isPrime[i] == false) continue;
		for (int j = 2; j * i <= maxNum; j++) {	// j는 계수
			isPrime[j * i] = false;
		}
	}
}

bool isPalin(int x) {
	string s = to_string(x);
	for (int i = 0; i != s.size(); i++) {
		if (s[i] != s[s.size() - 1 - i]) {
			return false;
		}
	}
	return true;
}

void solution() {
	checkPrime();
	int n;
	cin >> n;
	for (int i = n; i <= maxNum; i++) {
		if (isPrime[i] && isPalin(i)) {
			cout << i;
			return;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	//cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}