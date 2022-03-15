#include <iostream>
#include <vector>
using namespace std;

void solution() {
	int l;
	cin >> l;
	string s;
	cin >> s;
	long long coef = 1;
	long long sum = 0;
	const long long m = 1234567891;
	for (auto& ch : s) {
		sum += (ch - 'a' + 1) * coef;
		sum %= m;
		coef *= 31;
		coef %= m;
	}
	cout << sum;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}