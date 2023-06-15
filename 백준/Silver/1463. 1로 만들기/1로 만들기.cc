#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

vector<int> dat;

int min2(int n1, int n2) {
	return n1 < n2 ? n1 : n2;
}
int min3(int n1, int n2, int n3) {
	if (n1 <= n2 && n1 <= n3) {
		return n1;
	}
	else if (n2 <= n1 && n2 <= n3) {
		return n2;
	}
	return n3;
}
int dp(int x) {
	dat[0] = dat[1] = 0;
	//메모이제이션 dp[2] = 1; dp[4] = dp[2] + 1(횟수)
	for (int i = 2; i != x + 1; ++i) {
		if (!(i % 6)) {		
			dat[i] = min3(dat[i / 3] + 1, dat[i / 2] + 1, dat[i - 1] + 1);	//반복횟수, 비교대상1,...
		}
		else if (!(i % 3)) {
			dat[i] = min2(dat[i / 3] + 1, dat[i - 1] + 1);
		}
		else if (!(i % 2)) {
			dat[i] = min2(dat[i / 2] + 1, dat[i - 1] + 1);
		}
		else {
			dat[i] = dat[i - 1] + 1;
		}
	}
	return dat[x];
}
int main() {
	int x;
	scanf("%d", &x);
	dat.resize(x + 1, 0);
	printf("%d", dp(x));

	return 0;
}