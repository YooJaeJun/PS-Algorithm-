#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

vector<long long> dp_memo;
long long dp(long long n) {
	if (n <= 1) { return n; }
	else {
		if (dp_memo[n] > -1) {	//검사한 적 있으면 반환
			return dp_memo[n];
		}
		dp_memo[n] = dp(n - 1) + dp(n - 2);
		return dp_memo[n];
	}
}
int main() {
	long long n;
	scanf("%lld", &n);
	dp_memo.resize(n + 1, -1);	//검사 안 한 것들 -1 세팅.
	printf("%lld", dp(n));
	return 0;
}