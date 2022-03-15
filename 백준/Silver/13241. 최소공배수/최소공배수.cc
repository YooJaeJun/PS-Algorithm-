#include <iostream>
#include <vector>
using namespace std;

long long gcd(long long n1, long long n2) {
	if (n2 == 0) { return n1; }
	else { return gcd(n2, n1 % n2); }
}

long long lcm(long long n1, long long n2) {
	return (n1 * n2) / gcd(n1, n2);
}

void solution() {
	long long n1, n2;
	cin >> n1 >> n2;
	cout << lcm(n1, n2);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}