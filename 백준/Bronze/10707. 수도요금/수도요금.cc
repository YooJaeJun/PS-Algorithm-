#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solution() {
	int a, b, c, d, p;
	cin >> a >> b >> c >> d >> p;
	int s1 = a * p;
	cout << min(a * p, p <= c ? b : b + d * (p - c));
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}